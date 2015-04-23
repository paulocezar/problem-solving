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

#define MAXN 111

int ticket[MAXN];
int seen[MAXN][MAXN], seen_now;

int64 visited[2][MAXN][MAXN];

vector< pair<int,int> > gr[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int tc = 1;
	int N, E;
	
	while( cin >> N >> E && (N||E) ){
		REP( i, N ) gr[i].clear();
		
		REP( i, E ){
			int x, y, z;
			cin >> x >> y >> z;
			gr[x].PB( MP(y,z) );
			gr[y].PB( MP(x,z) );
		}
		
		int T;
		cin >> T;
		REP( i, T ) cin >> ticket[i];
		
		queue< pair<int,int> > q;
		q.push( MP(0,0) );
		
		seen[0][0] = ++seen_now;
		visited[0][0][0] = 1;
		visited[1][0][0] = 0;
		
		while( !q.empty() ){
			
			int place = q.front().first;
			int cur_ticket = q.front().second; q.pop();
			
			if( cur_ticket == T ) continue;
			
			REP( i, SIZE(gr[place]) ) if( gr[place][i].second == ticket[cur_ticket] ){
				
				int64 inpath[2];
				inpath[0] = visited[0][place][cur_ticket];
				inpath[1] = visited[1][place][cur_ticket];
				int nplace = gr[place][i].first;
				
				if( nplace < 50 ) inpath[0] |= (1LL<<nplace);
				else inpath[1] |= (1LL<<(nplace-50));
				
				if( seen[ nplace ][cur_ticket+1] != seen_now ){
					
					seen[ nplace ][cur_ticket+1] = seen_now;
					visited[0][ nplace ][ cur_ticket+1 ] = inpath[0];
					visited[1][ nplace ][ cur_ticket+1 ] = inpath[1];
					q.push( MP(nplace,cur_ticket+1) );
					
				} else {
					
					visited[0][ nplace ][cur_ticket+1] |= inpath[0];
					visited[1][ nplace ][cur_ticket+1] |= inpath[1];

				}
			}
		}
		
		int ans = 0;
		if( seen[N-1][T] == seen_now ){
			REP( i, N ){
				if( i < 50 ) ans += ((visited[0][N-1][T]>>i)&1LL);
				else ans += ((visited[1][N-1][T]>>(i-50))&1LL);
			}
		}
		cout << "Tour " << tc++ << ": " << ans << "\n";
		
	}
	
	return 0;
}

























