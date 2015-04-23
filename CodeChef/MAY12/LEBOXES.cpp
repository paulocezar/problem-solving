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


int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

int v[33];
int c[33], d[33];
double p[33];

int minv[2][33][33];

struct comb_t{
	int money;
	double prob;
	comb_t(int m = 0, double p = 0.0) : money(m), prob(p) {}
	bool operator < (const comb_t &c ) const{
		return money < c.money;
	}
};

int main( int argc, char* argv[] ){
	
	int t = next_int();
	while( t-- ){
		int n = next_int();
		int m = next_int();
		
		REP( i, n ){
			v[i] = next_int();
			p[i] = next_int(); p[i] /= 100.0;
		}
		
		REP( i, m ){
			c[i] = next_int();
			d[i] = next_int();
		}
		
		REP( qt_d, n+1 ) REP( qt_i, m+1 ) minv[0][qt_d][qt_i] = 2e9;
		minv[0][0][0] = 0;
		
		int old = 0, cur = 1;
		
		REP( item, m ){			
			REP( qt_d, n+1 ){
				REP( qt_i, m+1 ){
					int &res = minv[cur][qt_d][qt_i];
					res = minv[old][qt_d][qt_i];
										
					if( d[item] <= qt_d && qt_i ){
						int nqt_d = qt_d - d[item];
						while( nqt_d >= 0 ){
							res = min( res, c[item] + minv[old][ nqt_d ][ qt_i-1 ] );					
							nqt_d--;
						}
					}
				}
			}
			old = !old;
			cur = !cur;
		}
		
		
		int n1 = n/2;
		int lim = (1<<n1);
		
		vector< comb_t > mayhave[n1+1];
		
		REP( mask, lim ){			
			int mony = 0, diam = 0;
			double prob = 1.0;
			REP( i, n1 ) if( mask & (1<<i) ){
				mony += v[i];
				prob *= p[i];
			} else {
				diam++;
				prob *= (1.0-p[i]);
			}
				
			mayhave[diam].PB( comb_t(mony,prob) );			
		}
	
		REP( i, n1+1 ){
			sort( mayhave[i].begin(), mayhave[i].end() );
			mayhave[i].PB( comb_t(2e9,0.0) );
			RREP( j, SIZE(mayhave[i])-1 )
				mayhave[i][j].prob += mayhave[i][j+1].prob;
		}
			
		int n2 = n-n1;
		lim = (1<<n2);
		double ans = 0.0;
		REP( mask, lim ){
			
			int mony = 0, diam = 0;
			double prob = 1.0;
			REP( i, n2 ) if( mask & (1<<i) ){
				mony += v[n1+i];
				prob *= p[n1+i];
			} else {
				diam++;
				prob *= (1.0-p[n1+i]);
			}
			
			FOR(d_ndd,0,n1){	
				FOR( qt_i, 1, m ) if( minv[old][d_ndd+diam][qt_i] != 2e9 ){
					vector< comb_t >::iterator it, it2;
					
					it = lower_bound( ALL(mayhave[d_ndd]), comb_t(minv[old][diam+d_ndd][qt_i] - mony) );
					if( qt_i < m ){
						it2 = lower_bound( ALL(mayhave[d_ndd]), comb_t(minv[old][diam+d_ndd][qt_i+1] - mony) );
						ans += (double(qt_i) * prob * ((it->prob) - (it2->prob)));
					} else ans += (double(qt_i) * prob * (it->prob));	
					
				}
			}
			
		}			
		printf("%.4lf\n", ans );
 		
	}
	
	return 0;
}

























