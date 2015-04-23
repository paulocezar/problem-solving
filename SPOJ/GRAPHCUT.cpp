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

#define MAXN 501
#define MAXE 10000

int u[MAXE], v[MAXE];

vector< int > gr[2*MAXN];
char color[MAXN];
int cmpnt[MAXN];
int nid[MAXN];

int has[MAXN][MAXN], has_now = 0;

bool bip( int N ){
	
	int comp = -1;
	
	REP( i, N ) if( SIZE(gr[i]) && color[i] == -1 ){
		queue< int > q;
		color[i] = 0;
		q.push( i );
		comp++;
		
		while( !q.empty() ){
			
			int x = q.front(); q.pop();
			cmpnt[x] = comp;
			//cout << "at " << x << " color " << int(color[x]) << endl;
			REP( j, SIZE(gr[x]) ){
				//cout << "\t" << gr[x][j] << " color " << int(color[ gr[x][j] ]) << " "; 
				if( color[gr[x][j]] == -1 ){
					color[gr[x][j]] = !color[x];
					//cout << " push with " << int(color[gr[x][j]]);
					q.push( gr[x][j] );
				} else if( color[gr[x][j]] == color[x] ){
					//cout << gr[x][j] << " " << x << endl;
					return false;
				}
			//	cout << endl;
			}
			
		}
	}
	
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		
		int N, E, K;
		cin >> N >> E >> K;
		
		REP( i, N ){ gr[i].clear(); color[i] = -1; }
		REP( i, E ){ cin >> u[i] >> v[i]; u[i]--; v[i]--; }
		
		REP( i, K ){
			gr[u[i]].PB(v[i]);
			gr[v[i]].PB(u[i]);
		}
		
		bool ok = bip(N);
		if( ok ){
			
			int mx = -1;
			REP( i, N ) mx = max( mx, cmpnt[i] );
			
			int rmx = mx;
			mx = 2*(mx+1);			
			REP( i, N ) if( color[i] == -1 ){
				nid[i] = mx++;
			} else nid[i] = 2*cmpnt[i]+color[i];
			
			N = mx;
			REP( i, N ) gr[i].clear();
			
			int ax = 0;
			has_now++;
			
			while( ax <= rmx ){
				int uu = 2*ax; int vv = uu+1;
				has[uu][vv] = has[vv][uu] = has_now;
				gr[uu].PB( vv );
				gr[vv].PB( uu );
				ax++;
			}
			
			FOR( i, K, E-1 ){
				if( nid[ u[i] ] != nid[ v[i] ] ){
					
					int nu = SIZE( gr[ nid[u[i]] ] );
					int nv = SIZE( gr[ nid[v[i]] ] );
					
					REP( j, nu ){
						int vv = gr[ nid[u[i]] ][j];
						int uu = nid[v[i]];
						
						if( has[uu][vv] != has_now ){
							has[uu][vv] = has[vv][uu] = has_now;
							gr[uu].PB( vv );
							gr[vv].PB( uu );
						}	
					}
					REP( j, nv ){
						int vv = gr[ nid[v[i]] ][j];
						int uu = nid[u[i]];
						
						if( has[uu][vv] != has_now ){
							has[uu][vv] = has[vv][uu] = has_now;
							gr[uu].PB( vv );
							gr[vv].PB( uu );
						}
					}
					
				}
			}
			
			REP( i, N ) color[i] = -1;
			
			//REP( i, N ) { cout << "i: " << i << " -- "; REP( j, SIZE(gr[i])) cout << gr[i][j] << " "; cout << endl;}
			ok = bip(N);
		}
		
		if( ok ) cout << "YES\n";
		else cout << "NO\n";
		
	}
	
		
	return 0;
}

























