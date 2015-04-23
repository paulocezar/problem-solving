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

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int seen[2001][2001];
inline bool ok( int x, int y ){ return ( (x>=0) && (x<2001) && (y>=0) && (y<2001) ); }

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int p, s, xx, yy;
	while( (cin >> p) && p ){
		
		FILL( seen, -1 );
		
		queue< pair<int,int> >q;
		REP( i, p ){
			cin >> xx >> yy;
			q.push( MP(xx, yy) );
			seen[xx][yy] = 0;
		}
		cin >> s;
		REP( i, s ){
			cin >> xx >> yy;
			seen[xx][yy] = -2;
		}
		int ans = INF;
		pair<int,int> cur;
		while( !q.empty() ){
			cur = q.front(); q.pop();
			REP( i, 4 ){
				xx = cur.first+ds[i][0];
				yy = cur.second+ds[i][1];
				if( ok( xx, yy ) && seen[xx][yy] < 0 ){
					if( seen[xx][yy] == -2 ){ ans = seen[cur.first][cur.second]+1; goto hell; }
					seen[xx][yy] = seen[cur.first][cur.second]+1;
					q.push( MP(xx,yy) );
				}
			}
		}
	hell:
		cout << ans << "\n";
	}
	return 0;
}




















