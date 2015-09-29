#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		int C;
		cin >> C;
		
		char ok[256][256];
		char oppose[256][256];
		FILL( ok, 0 );
		FILL( oppose, 0 );
		
		string elmts;
		REP( i, C ){
			cin >> elmts;
			ok[ elmts[0] ][ elmts[1] ] = ok[ elmts[1] ][ elmts[0] ] = elmts[2];
		}
		
		int D;
		cin >> D;
		REP( i, D ){
			cin >> elmts;
			oppose[ elmts[0] ][ elmts[1] ] = 1;
			oppose[ elmts[1] ][ elmts[0] ] = 1;
		}
		
		int N;
		cin >> N;
		cin >> elmts;
	
		string now = "";
		REP( i, N ){
			if( SIZE(now) && ok[ now[SIZE(now)-1] ][ elmts[i] ] ){
				
				now[SIZE(now)-1] = ok[ now[SIZE(now)-1] ][ elmts[i] ];
			
			} else {
				
				bool add = true;
				RREP( j, SIZE(now) ) if( oppose[ now[j] ][ elmts[i] ] ){
					now = "";
					add = false;
					break;
				}
				
				if( add ) now += elmts[i];
			
			}
		}
		
		cout << "Case #" << tc << ": [";
		REP( i, SIZE(now) ){ cout << now[i]; if( i+1 != SIZE(now) ) cout << ", ";  }
		cout << "]\n";
		
	}
	
	return 0;
}
