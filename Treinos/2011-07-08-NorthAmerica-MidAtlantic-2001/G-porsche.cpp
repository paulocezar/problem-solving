#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof( (X).begin() )
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for( int i = a; i <= b; ++i)
#define RFOR(i, b, a) for( int i = b; i >= a; --i)
#define REP(i, N) for( int i = 0; i < N; ++i)
#define RREP(i, N) for( int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 22
int64 cost[MAXN], prof[MAXN];
int carac[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	int tc = 1;
	
	cin >> t;
	while( t-- ){
		
		int64 mn, mx;
		int crc, cli;
		cin >> mn >> mx >> crc >> cli;
		
		for( int i = 0; i < crc; i++ ) cin >> cost[i];
		
		for( int i = 0; i < cli; i++ ){
			int n;
			cin >> n;
			carac[i] = 0;
			while( n-- ){
				int c; cin >> c;
				carac[i] |= (1<<(c-1));
			}
			cin >> prof[i];
		}
		
		int64 profindex = 0, bprof;
		int64 margin = 0;
		int batt = 0;
		int ucarac = (1<<crc) - 1;
		
		
		int lmask =  1 << crc;
		for( int mask = 1; mask < lmask; mask++ ){
			
			int64 mcost = 0;
			for( int i = 0; i < crc; i++ ) if( mask & (1<<i) ) mcost += cost[i];
			if( mn <= mcost && mcost <= mx ){
				
				int att = 0;
				int64 mprof = 0;
				for( int i = 0; i < cli; i++ ) if( !( carac[i] & (~mask) ) ){
					att |= (1<<i);
					mprof += prof[ i ];
				}
				
				int64 mprofindex = int64( round( ( double(mprof) / double(mcost) ) * 1000.0 ) ); 
				if( mprofindex > profindex ){
					bprof = mprof;
					profindex = mprofindex;
					margin = mprof - mcost;
					batt = att;
					ucarac = mask;
				} else if( mprofindex == profindex ){
					if( mprof-mcost > margin ){
						bprof = mprof;
						profindex = mprofindex;
						margin = mprof - mcost;
						batt = att;
						ucarac = mask;
					} else if( mprof-mcost == margin ){
						if( __builtin_popcount(mask) < __builtin_popcount(ucarac) ){
							bprof = mprof;
							profindex = mprofindex;
							margin = mprof - mcost;
							batt = att;
							ucarac = mask;
						} else if( __builtin_popcount(mask) == __builtin_popcount(ucarac) ){
							if( __builtin_popcount(att) > __builtin_popcount(batt) ){
								bprof = mprof;
								profindex = mprofindex;
								margin = mprof - mcost;
								batt = att;
								ucarac = mask;	
							}
						}
					}
				}
				
			}
		}
		
		cout << "Feature Set " << tc++ << '\n';
		cout << profindex/1000LL << "." << setw(3) << setfill('0') << profindex%1000LL << "\n";
		cout << bprof << "\n" << bprof-margin << "\n";
		bool flg = false;
		for( int i = 0; i < crc; i++ ) if( ucarac & (1<<i) ){
			cout << i+1 << " ";
		}
		cout << "\n";
		flg = false;
		for( int i = 0; i < cli; i++ ) if( batt & (1<<i) ){
			cout << i+1 << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
