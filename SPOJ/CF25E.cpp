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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100100
string x[3];
int p[3*MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> x[0] >> x[1] >> x[2] ){
		
		int ans = SIZE(x[0]) + SIZE(x[1]) + SIZE(x[2]);
		sort( x, x+3 );
		
		do{
			//cout << "\t" << x[0] << " " << x[1] << " " << x[2] << endl;
			
			int cur = SIZE(x[0]);
			string curs = x[0];
			int n = SIZE(x[1]);
			
			p[0] = p[1] = 0;
			FOR( i, 2, n ){
				int j = p[i-1];
				while( x[1][i-1] != x[1][j] ){
					if( j == 0 ){ j = -1; break; }
					j = p[j];
				}
				p[i] = ++j; 
			}
			
			int a = 0;
			int b = 0;
			bool need = true;
			
			while( a < cur ){
				if( curs[a] == x[1][b] ) a++, b++;
				else if( b ) b = p[b];
				else a++;
				if( b == n ){
					need = false;
					break;
				}
			}
			
			if( need ){
				cur += SIZE(x[1])-b;
				FOR( i, b, SIZE(x[1])-1 ) curs += x[1][i];
			}
						
			n = SIZE(x[2]);
			p[0] = p[1] = 0;
			FOR( i, 2, n ){
				int j = p[i-1];
				while( x[2][i-1] != x[2][j] ){
					if( j == 0 ){ j = -1; break; }
					j = p[j];
				}
				p[i] = ++j; 
			}
			
			a = 0;
			b = 0;
			need = true;
			
			while( a < cur ){
				if( curs[a] == x[2][b] ) a++, b++;
				else if( b ) b = p[b];
				else a++;
				if( b == n ){
					need = false;
					break;
				}
			}
			
			if( need ){
				cur += SIZE(x[2])-b;
				//FOR( i, b, SIZE(x[2])-1 ) curs += x[2][i];
			}
			//cout << curs << endl;
			
			ans = min( ans, cur );
			
		} while( next_permutation(x, x+3) );
		cout << ans << "\n";
	}
	
	return 0;
}




















