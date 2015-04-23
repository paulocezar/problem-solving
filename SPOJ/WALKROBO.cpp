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

int grid[15][15];

int dist[1<<20];
int seen[1<<20];
int seen_now;

int encode( int x, int y, int mask ){
	mask <<= 4;
	mask |= y;
	mask <<= 4;
	mask |= x;
	return mask;
}

void decode( int wut, int &x, int &y, int &mask ){
	x = wut&15; wut >>= 4;
	y = wut&15; wut >>= 4;
	mask = wut;	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int M, N, K, T;
	while( (cin >> M >> N >> K >> T) && (M||N||K||T) ){
		seen_now++;
		int dx[K], dy[K];
		REP( i, K ) cin >> dx[i] >> dy[i];
		
		int moves = 0;
		REP( i, T ){
			int x; cin >> x;
			moves |= (1<<(x-1));
		}
		RREP( i, M ) REP( j, N ) cin >> grid[i][j];
		
		queue< int > q;
		int x, y, nxt, cur = encode(0,0,moves);
		q.push( cur );
		seen[cur] = seen_now;
		dist[cur] = 0;
		
		int steps = -1;
		while( !q.empty() ){
			cur = q.front(); q.pop();
			decode( cur, x, y, moves );
			if( x == N-1 && y == M-1 ){ steps = dist[cur]; break; }
			
			REP( i, K ) if( moves & (1<<i) ){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if( 0 <= nx && nx < N && 0 <= ny && ny < M ){
					nxt = encode(nx,ny,moves);
					if( seen[nxt] != seen_now ){
						seen[nxt] = seen_now;
						dist[nxt] = dist[cur]+1;
						q.push( nxt );
					}
				} 
			}
			if( grid[y][x] ){
				nxt = encode( x, y, moves|(1<<(grid[y][x]-1)));
				if( seen[nxt] != seen_now ){
					seen[nxt] = seen_now;
					dist[nxt] = dist[cur]+1;
					q.push( nxt );
				}
			}
			
		}
		
		cout << "Case #" << seen_now << ": " << steps << "\n";
	}
		
	return 0;
}

























