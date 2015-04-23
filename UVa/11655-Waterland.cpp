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
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 5555
vector<int> gr[MAXN], gr2[MAXN];
int in[MAXN], in2[MAXN];
int64 S[MAXN], T[MAXN];

const int64 MOD = 100000LL;
bool seen[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, N, M, u, v;
	
	cin >> t;
	FOR( tc, 1, t ){
		
		cin >> N >> M;
		REP( i, N ){
			gr[i].clear();  in[i] = 0;
			gr2[i].clear(); in2[i] = 0;
			seen[i] = false;
			S[i] = 0, T[i] = 0;
		}
		REP( i, M ){
			cin >> u >> v; u--, v--;
			gr[u].PB( v ); in[v]++;
			gr2[v].PB( u ); in2[u]++;
		}
		
		queue<int> q; q.push( 0 ); seen[0] = true;
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE(gr[u]) ) if( !seen[gr[u][i]] ){
				seen[ gr[u][i] ] = true;
				q.push( gr[u][i] );
			}
		}
		REP( i, N ) if( !seen[i] ){
			REP( j, SIZE(gr[i]) ) in[ gr[i][j] ]--;
		} else seen[i] = false;
			
		q.push( N-1 ); seen[N-1] = true;
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE(gr2[u]) ) if( !seen[gr2[u][i]] ){
				seen[ gr2[u][i] ] = true;
				q.push( gr2[u][i] );
			}
		}
		REP( i, N ) if( !seen[i] ){
			REP( j, SIZE(gr2[i]) ) in2[ gr2[i][j] ]--;
		}
		
		S[0] = 1;
		q.push( 0 );
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE( gr[u]) ){
				v = gr[u][i];
				S[v] += S[u]; 
				S[v] %= MOD;
				in[v]--;
				if( !in[v] ) q.push( v );
			}
		}
		
		T[N-1] = 1;
		q.push( N-1 );
		while( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE( gr2[u]) ){
				v = gr2[u][i];
				T[v] += T[u];
				T[v] %= MOD;
				in2[v]--;
				if( !in2[v] ) q.push( v );
			}
		}
		
		int64 nd = 0;
		FOR( i, 1, N-1 ){
			nd += ( (S[i]*T[i]) % MOD );
			nd %= MOD; 
		} 
		cout << "Case " << tc << ": " << nd << " " << S[N-1] << '\n';		
		
	}
	return 0;
}




















