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
		
		int n;
		cin >> n;
		
		vector< pair<char,int> > seq(n);
		vector< int > orange;
		vector< int > blue;
		REP( i, n ){
			cin >> seq[i].first >> seq[i].second;
			if( seq[i].first == 'O' ) orange.pb( seq[i].second );
			else blue.pb( seq[i].second );
		}
		
		int opos, bpos;
		opos = bpos = 1;
		
		vector< int >::iterator oit, bit;
		oit = orange.begin();
		bit = blue.begin();
		int ans = 0;
		
		REP( i, n ){
			
			int dor, dbl;
			
			if( oit != orange.end() ) dor = ABS( *oit - opos );
			else dor = INF;
			
			if( bit != blue.end() ) dbl = ABS( *bit - bpos );
			else dbl = INF;
			
			if( seq[i].first == 'O' ){
				
				ans += dor + 1;
				opos = seq[i].second;
				oit++;
				
				if( bit != blue.end() ){
					if( *bit > bpos ) bpos = bpos + MIN( dor+1, dbl );
					else bpos = bpos - MIN( dor+1, dbl );
				}
				
			} else {
				
				ans += dbl + 1;
				bpos = seq[i].second;
				bit++;
				
				if( oit != orange.end() ){
					if( *oit > opos ) opos = opos + MIN( dor, dbl+1 );
					else opos = opos - MIN( dor, dbl+1 );
				}
				
			}
			
		}
	
		cout << "Case #" << tc << ": " << ans << "\n";	
	}	
	
	return 0;
}
