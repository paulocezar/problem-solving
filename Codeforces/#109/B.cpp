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

int main( int argc, char* argv[] ){
        
        ios::sync_with_stdio( false );

		int n, m;
		cin >> n >> m;
		
		vector< int > primefacts[n+1];
		int prime[n+1];
		bool on[n+1];
		
		primefacts[1].PB( 1 );
		on[1] = false;
		prime[1] = 0;
		
		for( int i = 2; i <= n; i++ ){
			if( SIZE(primefacts[i]) == 0 ){
				primefacts[i].PB( i );
				for( int j = i+i; j <= n; j+=i ) primefacts[j].PB( i );
			}
			on[i] = false;
			prime[i] = 0;
		}	
		
		char wut;
		int pos;
		
		while( m-- ){
			cin >> wut >> pos;
			
			if( wut == '+' ){
				if( on[pos] ){
					cout << "Already on\n";
				} else {
					bool ok = true;
					REP( i, SIZE(primefacts[pos]) ){
						if( prime[ primefacts[pos][i] ] ){
							cout << "Conflict with " <<  prime[primefacts[pos][i]] << "\n";
							ok = false;
							break;
						}
					}
					if( ok ){
						cout << "Success\n"; 
						on[pos] = true;
						REP( i, SIZE(primefacts[pos]) )
							prime[primefacts[pos][i]] = pos;
					}	
				}
			} else {
				if( !on[pos] ) cout << "Already off\n";
				else {
					on[pos] = false;
					cout << "Success\n";
					REP( i, SIZE(primefacts[pos]) )
						prime[primefacts[pos][i]] = 0;
				}
			}
		}

        return 0;
}
















