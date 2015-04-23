#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct event_t {
	int ax, frm;
	char wut;
	event_t( int a = 0, int b = 0, char c = 0 ) : ax(a), frm(b), wut(c){}
	bool operator < ( const event_t& a ) const {
		if( ax != a.ax ) return ax < a.ax;
		return wut < a.wut;
	}
};

struct rect_t{
	int x1, y1, x2, y2;
	rect_t( int a = 0, int b = 0, int c = 0, int d = 0 ): x1(a), y1(b), x2(c), y2(d) {}
};

rect_t rect[22];
event_t eventx[4*22], eventy[4*22];
int N, szex, szey;

pair<int64,int64> area(){
	szex = 0, szey = 0;
	for( int i = 0; i < N; i++ ){
		eventx[szex++] = event_t(rect[i].x1, i, 0 );
		eventx[szex++] = event_t(rect[i].x2, i, 1 );
		eventy[szey++] = event_t(rect[i].y1, i, 0 );
		eventy[szey++] = event_t(rect[i].y2, i, 1 );
	}
	
	sort( eventx, eventx+szex );
	sort( eventy, eventy+szey );
	int active = 0;
	
	active |= 1<<eventx[0].frm;
	
	pair<int64,int64> ans = MP(0,0);
	for( int i = 1; i < szex; i++ ){
		
		int in = 0;
		int lst = 0;
        bool first = true;
		for( int j = 0; j < szey; j++ ){
			if( !(active & (1<<eventy[j].frm)) ) continue;
			if( in ){
                int64 dx = eventx[i].ax-eventx[i-1].ax;
                int64 dy = eventy[j].ax-lst;
                ans.first += dx*dy;
                if(first) ans.second += 2*dx;
                first = false;
                lst = eventy[j].ax;
            } else lst = eventy[j].ax;
			
			if( eventy[j].wut ) in--;
			else in++;
            if(in == 0) first = true;
		}
        
		if( eventx[i].wut ) active ^= (1<<eventx[i].frm);
		else active |= (1<<eventx[i].frm);
	}
	
	active |= 1<<eventy[0].frm;
	for( int j = 1; j < szey; j++ ){
		
		int in = 0;
		bool first = true;
		for( int i = 0; i < szex; i++ ){
			if( !(active & (1<<eventx[i].frm)) ) continue;
			if( in ){
                int64 dy = eventy[j].ax-eventy[j-1].ax;
                
                if(first) ans.second += 2*dy;
                first = false;
            }
            
			if( eventx[i].wut ) in--;
			else in++;
            if(in == 0) first = true;
		}
        
		if( eventy[j].wut ) active ^= (1<<eventy[j].frm);
		else active |= (1<<eventy[j].frm);
	}
	
	return ans;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    while(cin >> N && N) {
        int x, y, L, C;
        REP(i,N) {
            cin >> x >> y >> L >> C;
            rect[i].x1 = x;
            rect[i].x2 = x+L;
            rect[i].y1 = y;
            rect[i].y2 = y+C;
        }
        pair<int64,int64> a = area();
        cout << a.first << " " << a.second << "\n";
    }
    
    
    return 0;
}
















