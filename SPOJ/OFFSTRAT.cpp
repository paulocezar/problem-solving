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

int mpn[111][111];
int ncur, cur[111][111], vis_now, vis[111*111];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, w, h;
	
	cin >> t;
	
	while( t-- ){
		
		cin >> w >> h;
		
		ncur++;
		
		int curid = 0;
		cur[w][h/2] = ncur;
		mpn[w][h/2] = curid++;
		
		vector< vector<int> > gr;
		gr.PB( vector<int>() );
		
		int M; cin >> M;
		bool ok = true;
		
		while( M-- ){
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			
			if( ok ){
				if( x0 > x1 ) ok = false;
				else {
					
					if( cur[x0][y0] != ncur ){ cur[x0][y0] = ncur; mpn[x0][y0] = curid++; gr.PB( vector<int>() ); }
					if( cur[x1][y1] != ncur ){ cur[x1][y1] = ncur; mpn[x1][y1] = curid++; gr.PB( vector<int>() ); }
					
					gr[ mpn[x1][y1] ].PB( mpn[x0][y0] );
				
				}
			}
			
		}
		
		if( ok ){
			
			queue< int > q;
			q.push( 0 );
			vis[0] = ++vis_now;
			int seen = 0;
			
			while( !q.empty() ){
				seen++;
				int u = q.front(); q.pop();
				
				REP( i, SIZE(gr[u]) ){
					int v = gr[u][i];
					
					if( vis[v] != vis_now ){
						vis[v] = vis_now;
						q.push(v);
					}
					
				}
				
			}
			
			if( seen != curid ) cout << "No\n";
			else cout << "Yes\n";
			
		} else cout << "No\n";
		
	}
			
	return 0;
}

























