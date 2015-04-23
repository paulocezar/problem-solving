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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
#define MAXN 111
#define MAXM 5111

int N, M;
int64 f[MAXN][MAXN], c[MAXN][MAXN];
int64 dist[MAXN], aug[MAXN], parent[MAXN];
int u[MAXM], v[MAXM], w[MAXM];

int64 augment(){
	int64 ww;
	FOR( i, 0, N ) dist[i] = aug[i] = 2e15, parent[i] = -1;
	dist[0] = 0;
	bool need;
	do{
		need = false;
		FOR( k, 0, M ){
			int i = u[k];
			int j = v[k];
			if( f[i][j] < c[i][j] ){
				if( f[i][j] < 0 ) ww = -w[k]; else ww = w[k];
				if( dist[j] > dist[i]+ww ){
					dist[j] = dist[i]+ww;
					aug[j] = min( aug[i], c[i][j]-f[i][j] );
					parent[j] = i;
					need = true;
				}
			}
			i = v[k];
			j = u[k];
			if( f[i][j] < c[i][j] ){
				if( f[i][j] < 0 ) ww = -w[k]; else ww = w[k];
				if( dist[j] > dist[i]+ww ){
					dist[j] = dist[i]+ww;
					aug[j] = min( aug[i], c[i][j]-f[i][j] );
					parent[j] = i;
					need = true;
				}
			}			
		}
	} while( need );
	
	if( parent[N] == -1 ) return 0;
	
	int v = N;
	while( parent[v] != -1 ){
		f[parent[v]][v] += aug[N];
		f[v][parent[v]] -= aug[N];
		v = parent[v];
 	}
	return dist[N]*aug[N];
}

int64 minCostMaxFlow(){
	int64 cf, ans = 0;
	while( true ){
		cf = augment();
		if( cf == 0 ) break;
		ans += cf;
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int64 D, K;
	u[0] = 0, v[0] = 1, w[0] = 0;
	while( cin >> N >> M ){
		FILL( f, 0 ); FILL( c, 0 );
		
		FOR( i, 1, M ) cin >> u[i] >> v[i] >> w[i]; 
		cin >> D >> K;
		FOR( i, 1, M ) c[u[i]][v[i]] = c[v[i]][u[i]] = K;
		c[0][1] = c[1][0] = D;
		int64 ans = minCostMaxFlow();
		
		if( f[0][1] == D ) cout << ans << "\n";
		else cout << "Impossible.\n";
 	}
	return 0;
}




















