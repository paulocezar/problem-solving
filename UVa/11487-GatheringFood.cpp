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

#define MAXN 11
int grid[MAXN][MAXN];
int N, seen[1<<15], in[1<<15], ways[1<<15];
int ds[][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
vector< int > gr[1<<15];

#define OK(a,b) (((a<N)&&(b<N)&&(a>=0)&&(b>=0)))

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string line;
	int k, ni, nj, nk, cur, nxt;
	int tc = 1;
	
	while( (cin>>N) && N ){
		int need = 0;
		int si = -1, sj = -1, ti = -1, tj = -1;
		REP( i, N ){
			cin >> line;
			REP( j, N ){
				if( 'A' <= line[j] && line[j] <= 'Z' ){
					if( line[j] == 'A' ) si = i, sj = j;
					grid[i][j] = int(line[j]-'A');
					if( grid[i][j] > need ){
						need = grid[i][j];
						ti = i, tj = j;
					}
				}
				else if( line[j] == '#' ) grid[i][j] = 50;
				else grid[i][j] = -1;
			}
		}
		
		if( ti == -1 ) ti = si, tj = sj;
		FILL( seen, INF );
		
		queue< int > q;
		int beg = (si << 9) + (sj << 5);
		q.push( beg );
		seen[ beg ] = 0;
		gr[ beg ].clear();
		ways[ beg ] = 1;
		
		while( !q.empty() ){
			cur = q.front(); q.pop();
			si = cur;
			k = si & 0x1F; si >>= 5;
			sj = si & 0xF; si >>= 4;
			
			if( k == need ) continue;
						
			REP( dir, 4 ){
				ni = si + ds[dir][0];
				nj = sj + ds[dir][1];
				if( OK(ni,nj) && ( grid[ni][nj] < k || grid[ni][nj] == k+1 ) ){
					nk = k + (grid[ni][nj]==(k+1));
					nxt = (ni<<9) + (nj<<5) + nk;
					if( seen[cur]+1 < seen[ nxt ]  ){
						seen[nxt] = seen[cur]+1;
						q.push( nxt );
						in[ nxt ] = 0;
						ways[nxt] = 0;
						gr[ nxt ].clear();
					}
					if( seen[cur]+1 == seen[nxt] ){
						in[ nxt ]++;
						gr[cur].PB( nxt );
					}
				}
			}	
		}
		
		int ans = seen[ (ti<<9) + (tj<<5) + need ];
		if( ans == INF ){
			cout << "Case " << tc++ << ": Impossible\n";
		} else {
			
			while( !q.empty() ) q.pop();
			
			q.push( beg );
			while( !q.empty() ){
				cur = q.front(); q.pop();
				REP( i, SIZE(gr[cur]) ){
					ways[ gr[cur][i] ] += ways[ cur ];
					ways[ gr[cur][i] ] %= 20437;
					in[ gr[cur][i] ]--;
					if( !in[gr[cur][i]] ) q.push( gr[cur][i] );
				}
			}
			cout << "Case " << tc++ << ": " << ans << " " << ways[(ti<<9) + (tj<<5) + need] << "\n";
		}
	}
	
	return 0;
}




















