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
	
	int n, k;
	string num;
	
	cin >> n >> k;
	cin >> num;
	
	map< char, int > qtde;
	REP( i, SIZE(num) ) qtde[num[i]]++;
	
	int ans = INF;
	vector< char > cand;
	
	for( char luck = '0'; luck <= '9'; luck++ ){
		
		int need = k - qtde[luck];
		int cost = 0;
		
		int dif = 1;
		while( need > 0 && dif <= 9 ){
			int has = 0;
			
			if( luck-dif >= '0' ) has += qtde[luck-dif];
			if( luck+dif <= '9' ) has += qtde[luck+dif];
			
			cost += dif*min( need, has );
			need -= min( need, has );
			dif++;
		}
		
		if( cost < ans ){
			ans = cost;
			cand.clear();
		}
		if( cost == ans ) cand.PB( luck );
		
	}
	cout << ans << "\n";
	if( ans == 0 ) cout << num << "\n";
	else {
		string nwnum = "";
		REP( i, SIZE(num) ) nwnum += '9';
		
		REP( x, SIZE(cand) ){
			char luck = cand[x];
			string cur = num;
			
			int need = k-qtde[luck];
			
			int dif = 1;
			while( need > 0 && dif <= 9 ){
				REP( i, SIZE(num) ) if( num[i] == luck+dif ){
					cur[i] = luck;
					need--;
					if( need == 0 ) break;
				}
				
				if( need == 0 ) break;
				RREP( i, SIZE(num) ) if( num[i] == luck-dif ){
					cur[i] = luck;
					need--;
					if( need == 0 ) break;
				}
				dif++;
			}
			
			nwnum = min( nwnum, cur );
		}
		
		cout << nwnum << "\n";
	}
	
	return 0;
}




















