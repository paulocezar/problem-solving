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

bool grt( string &a, string &b ){
	if( SIZE(a) > SIZE(b) ) return true;
	if( SIZE(a) < SIZE(b) ) return false;
	REP( i, SIZE(a) ) if( a[i] != b[i] ) return (a[i]>b[i]);
	return false;
}

void gen( int len, int K, string &res ){
	if( K == 1 ){
		res = "";
		REP( i, len ) res += '1';
	} else {
		res = "";
		REP( i, len-1 ) res += '0';
		res = '1' + res;
		K -= 2;
		int pos = len-K;
		int cur = 2;
		while( K-- ){
			res[pos] = (cur+'0');
			pos++; cur++;
		}
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, tc = 1, k;
	string n;
	
	int DBG = 2021;
	
	cin >> t;
	while( t-- ){
		
		cin >> n >> k;
		string ans;
		int sz = SIZE(n);
		
		if( tc == DBG ) cerr << n << " " << k << " ";
		
		int used = 0;
		REP( i, sz ) used |= (1<<(n[i]-'0'));
		ans = n;
		if( __builtin_popcount(used) != k ){
			
			RREP( i, sz ){
				for( char dig = n[i]+1; dig <= '9'; dig++ ){
					used = 1<<(dig-'0');
					for( int j = i-1; j >= 0; j-- ) used |= (1<<(n[j]-'0'));
					int kk = __builtin_popcount(used);
					if( kk <= k ){
						
						int len = sz-i-1;
						
						int pos = 0;
						vector< char > put;
						while( kk < k ){
							if( !(used & (1<<pos)) ){
								used |= (1<<pos); kk++;
								put.PB( char(pos+'0') );
							}
							pos++;
						}
						
						if( SIZE(put) <= len ){
							
							int mn = 0;
							while( !(used & (1<<mn)) ) mn++;
							while( SIZE(put) < len ) put.PB( char(mn+'0') );
							
							sort( ALL(put) );
							ans[i] = dig;
							REP( j, SIZE(put) ) ans[i+j+1] = put[j];
							
							goto hell;	
						}
												
					}							
				}
			}
			gen( max(sz+1,k), k, ans );
		}
	hell:	
		
		if( tc == DBG ) cerr << ans << endl;
		cout << "Caso " << tc++ << ": " << ans << "\n";
	}
	
	return 0;
}

























