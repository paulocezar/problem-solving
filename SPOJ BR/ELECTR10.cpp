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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + int64(c-'0');
		c = getchar_unlocked();
	}
	return res;
}
int64 next_lint(){
	int64 res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10LL*res + int64(c-'0');
		c = getchar_unlocked();
	}
	return res;
}

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
int szr, szex, szey;

int64 area(){
	if( szr == 0 ) return 0;
	
	szex = 0, szey = 0;
	for( int i = 0; i < szr; i++ ){
		eventx[szex++] = event_t(rect[i].x1, i, 0 );
		eventx[szex++] = event_t(rect[i].x2, i, 1 );
		eventy[szey++] = event_t(rect[i].y1, i, 0 );
		eventy[szey++] = event_t(rect[i].y2, i, 1 );
	}
	
	sort( eventx, eventx+szex );
	sort( eventy, eventy+szey );
	int active = 0;
	
	active |= 1<<eventx[0].frm;
	
	int64 ans = 0;
	for( int i = 1; i < szex; i++ ){
		
		int in = 0;
		int lst = 0;
		for( int j = 0; j < szey; j++ ){
			if( !(active & (1<<eventy[j].frm)) ) continue;
			if( in ){
				ans += int64(eventy[j].ax-lst)*int64(eventx[i].ax-eventx[i-1].ax);
				lst = eventy[j].ax;
			} else lst = eventy[j].ax;
			
			if( eventy[j].wut ) in--;
			else in++;
		}
		
		if( eventx[i].wut ) active ^= (1<<eventx[i].frm);
		else active |= (1<<eventx[i].frm);
	}
	
	return ans;
}

int R[22], C[22], P;

int64 area( int layer, int minN, int N, int minM, int M ){	
	
	szr = 0;
	int64 disconsider = 0;
	REP( i, P ){
		int x1 = max( minN-1, R[i]-layer-1 );
		int y1 = max( minM-1, C[i]-layer-1 );
		int x2 = min( N, R[i]+layer );
		int y2 = min( M, C[i]+layer );
		
		if( x1 <= x2 && y1 <= y2 ){
			if( x1 <= R[i] && R[i] <= x2 && y1 <= C[i] && C[i] <= y2 )
				disconsider++;
			rect[szr++] = rect_t(x1,y1,x2,y2);
		}
	}
	return area()-disconsider;
}

int main( int argc, char* argv[] ){
	
	int N, M;
	N = next_int();
	M = next_int();
	P = next_int();
	while( N || M || P ){
		
		REP( i, P ){ R[i] = next_int(); C[i] = next_int(); }
		
		int Q;
		Q = next_int();
		while( Q-- ){
			int64 q = next_lint();
			
			int lo = 1, hi = max(N,M);
			int layer;
			while( lo <= hi ){
				int mid = (lo+hi)/2;
				
				if( area(mid,1,N,1,M) >= q ){
					layer = mid;
					hi = mid-1;
				} else lo = mid+1;

			}
			
			q -= area(layer-1,1,N,1,M);
			
			lo = 1, hi = N;
			int line;
			while( lo <= hi ){
				int mid = (lo+hi)/2;
				int64 curpoints = area(layer,1,mid,1,M) - area(layer-1,1,mid,1,M);
				if( curpoints >= q ){
					line = mid;
					hi = mid-1;
				} else lo = mid+1;
			}
			q -= (area(layer,1,line-1,1,M) - area(layer-1,1,line-1,1,M));
		
			lo = 1, hi = M;
			int col;
			while( lo <= hi ){
				int mid = (lo+hi)/2;
				int64 curpoints = area(layer,line,line,1,mid)-area(layer-1,line,line,1,mid);
				if( curpoints >= q ){
					col = mid;
					hi = mid-1;
				} else lo = mid+1;
			}
			
			printf("%d %d\n", line, col);
		}
		puts("-");
		
		N = next_int();
		M = next_int();
		P = next_int();
	}
	
	return 0;
}

























