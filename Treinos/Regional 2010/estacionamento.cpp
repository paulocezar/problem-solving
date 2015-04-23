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

struct segment_t{
	int sz, pl;
	bool busy;
	segment_t( int ss = 0, int pp = -1, bool sh = false ) 
		: sz(ss), pl(pp), busy(sh) {}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int C, N, P, Q;
	char wut;
	
	while( cin >> C >> N ){
		
		list< segment_t > park;
		park.PB( segment_t( C ) );
		int ans = 0;
		REP( i, N ){
			cin >> wut;
			if( wut == 'C' ){
				cin >> P >> Q;
				FORIT( x, park ){
					if( !(x->busy) && x->sz >= Q ){
						ans += 10;
						park.insert( x, segment_t(Q,P,true) );
						x->sz -= Q;
						if( x->sz == 0 ) park.erase( x );
						break;
					}
				}
			} else {
				cin >> P;
				FORIT( x, park ){
					if( x->pl == P ){
						x->pl = -1;
						x->busy = false;
						
						if( x != park.begin() ){
							TI(park) prev, next;
							prev = x; prev--; 
							next = x; next++;
							
							if( !(prev->busy) ){
								x->sz += prev->sz;
								if( next != park.end() && !(next->busy) ){
									x->sz += next->sz;
									park.erase(next);
								}
								park.erase(prev);
							} else if( next != park.end() && !(next->busy) ){
								x->sz += next->sz;
								park.erase(next);
							}
							
						} else {
							
							TI(park) next;
							next = x; next++;
							
							if( next != park.end() && !(next->busy) ){
								x->sz += next->sz;
								park.erase(next);
							}
							
						}
						
					}
				}
			}
			
			//FORIT( x, park ) cout << x->bg << " " << x->sz << " " << x->pl << " " << x->busy << endl;
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}













