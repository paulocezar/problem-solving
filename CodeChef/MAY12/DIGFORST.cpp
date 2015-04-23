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
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXN 111

int N;
int val[MAXN];
vector< int > gr[MAXN];

int seen[ 420 ][ 64 * 100 ];

int main( int argc, char* argv[] ){
	
	N = next_int();
	while( N ){
		REP( i, N ){
			gr[i].clear();
			val[i] = next_int();
		}
		REP( i, N ) REP( j, N ){
			int wut = next_int();
			if( wut ) gr[i].PB( j );
		}
		
		int fmask = 0;
		if( val[0] > 1 ) fmask |= (1<<(val[0]-2));
		seen[ val[0] ][ fmask ] = val[0];
		
		priority_queue< pair< int, pair<int, int> > > q;
		q.push( MP(-val[0],  MP(val[0], fmask ) ) );	 
		
		while( !q.empty() ){
			int dis = -q.top().first;
			int mod = q.top().second.first;
			int u = q.top().second.second; q.pop();
			int mask = u & 63;
			u >>= 6;
			
			if( u == N-1 ){
				if( (mask & 1) && (mod % 2) ) goto keep_playing;
				if( (mask & 2) && (mod % 3) ) goto keep_playing;
				if( (mask & 4) && (mod % 4) ) goto keep_playing;
				if( (mask & 8) && (mod % 5) ) goto keep_playing;
				if( (mask & 16) && (mod % 6) ) goto keep_playing;
				if( (mask & 32) && (mod % 7) ) goto keep_playing;
				printf("%d\n", dis );				
				goto hell;
			}
		keep_playing:
		
			REP( i, SIZE(gr[u]) ){
				
				int add = val[ gr[u][i] ];
				int nmod = (mod*10 + add)%420;
				int nmask = mask;
				if( add > 1 ) nmask |= (1<<(add-2));
				int ns = (gr[u][i] << 6) | nmask;
				 
				if( !seen[nmod][ns] || seen[nmod][ns] > dis+add ){
					seen[nmod][ns] = dis+add;
					q.push( MP(-(dis+add), MP(nmod,ns)) );
				}
			}
			
		}
		puts("-1"); 
	hell:	
		N = next_int();
	}
	
	
	return 0;
}

























