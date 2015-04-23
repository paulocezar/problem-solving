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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t, N, M, A, B, ag;
	string line;
	
	cin >> t;
	FOR( tc, 1, t ){
		cin >> N >> M >> ag; cin.ignore();
		
		pair< int, string > a[ag];
		
		REP( i, ag ){
			getline( cin, line );
			REP( j, SIZE(line) )
				if( !( ('A' <= line[j] && line[j] <= 'Z')
					 	|| ('0' <= line[j] && line[j] <= '9')
					 ) ) line[j] = ' ';
			istringstream in( line );
			in >> a[ i ].second >> A >> B;
			a[ i ].first = 0;
			int NN = N;
			while( NN > M ){
				if( NN/2 >= M && (NN-(NN/2))*A >= B ){
					NN /= 2;
					a[i].first += B;
				} else if( NN/2 >= M ){
					a[i].first += (NN-(NN/2))*A;
					NN /= 2;
				} else if( NN-1 >= M ){
					NN--;
					a[i].first += A;
				}
			}			
		}
		sort( a, a+ag );
		cout << "Case " << tc << "\n";
		REP( i, ag ) cout << a[i].second << " " << a[i].first << "\n";
	}
	return 0;
}




















