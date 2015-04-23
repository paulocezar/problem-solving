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
				//  N -- S -- W -- E
int ds[][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct st{
	int x, y;
	char loc;
	st( int xx = 0, int yy = 0, char cc = 'A' ) : x(xx), y(yy), loc(cc) {}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, K, stp;
	char dir;
	cin >> N >> M;
	
	string grid[N];
	REP( i, N )
		cin >> grid[i];
	
	vector< int > line[N];
	vector< int > col[M];
	
	list< st > cand;

	REP( i, N ) REP( j, M ) {
		if( grid[i][j] == '#' ){
			line[i].PB( j );
			col[j].PB( i );
		} else if( 'A' <= grid[i][j] && grid[i][j] <= 'Z' )
			cand.PB( st(i, j, grid[i][j]) );
	}
	
	cin >> K;
	while( K-- ){
		if( cand.empty() ) break;
		cin >> dir >> stp;
		FORIT( i, cand ){
			switch( dir ){
				case 'N': 
					if( *(lower_bound( ALL(col[i->y]), i->x )-1) < (i->x - stp) ){
						i->x -= stp;
					} else{ i = cand.erase(i); i--; }
					break;
				case 'S':
					if( *(upper_bound( ALL(col[i->y]), i->x )) > (i->x + stp) ){
						i->x += stp;
					} else{ i = cand.erase(i); i--; }
					break;
				case 'W':
					if( *(lower_bound( ALL(line[i->x]), i->y )-1) < (i->y - stp) ){
						i->y -= stp;
					} else{ i = cand.erase(i); i--; }
					break;
				case 'E':
					if( *(upper_bound( ALL(line[i->x]), i->y )) > (i->y + stp) ){
						i->y += stp;
					} else{ i = cand.erase(i); i--; }
					break;
			}
		}
	}
	if( cand.empty() ) cout << "no solution\n";
	else {
		string ans = "";
		FORIT( x, cand ) ans += x->loc;
		sort( ALL(ans) );
		cout << ans << "\n";
	}	
	
	return 0;
}




















