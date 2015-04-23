#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 65536
int side[MAXN];

int ds[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );
	
	int t;
	int a, b;
	int x = 0, y = 0; 
	int K, N, M;
	
	scanf("%d", &t );
	FOR( tc, 1, t+1 ){
		
		printf("Caso %d\n", tc );
		scanf("%d %d", &a, &b );
		
		int cur = 1, step = 1;
		int dir = 0;
		x = y = 0;
		N = 0;
		while( N < MAXN ){
			if( y != (a*x + b) ){
				//cout << N << " " << x << " " << y << " - " << (y < (a*x + b)) << endl; getchar();
				side[N] = y < (a*x + b);
				N++;
			}
			x += ds[dir][0];
			y += ds[dir][1];
			cur--;
			if( !cur ){
				if( dir == 1 || dir == 3 ) step++;
				cur = step;
				dir = (dir+1) % 4;
			}
		}
		
		
		scanf("%d", &K );
		while( K-- ){
			scanf("%d %d", &N, &M );
			if( side[N] == side[M] ) puts( "Mesmo lado da fronteira" );
			else puts( "Lados opostos da fronteira" );
		}
	
	}
	
	return 0;
}




















