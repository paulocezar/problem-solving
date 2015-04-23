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
#define TI(X) typeof((X).begin)
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

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		
		map< string, int > search, document;
		
		string wrd, parsed;
		
		cin >> wrd;
		while( wrd != "----------" ){
			
			parsed = "";
			REP( i, SIZE(wrd) ) if( isalpha(wrd[i]) ) parsed += toupper( wrd[i] );
			if( parsed != "" ) search[parsed]++;
			
			cin >> wrd;
		}
		
		document.clear();
		cin >> wrd;
		bool flag = true;
		do {
		
			if( wrd == "----------" ){
				if( flag ) goto hell;
				else flag = true;
				
				double docscore = 0.0;
				for( map<string,int>::iterator it = search.begin(); it != search.end(); it++ )  docscore += sqrt(  it->second*( document[it->first] ) );
				cout << fixed << setprecision(2) << docscore << "\n";
				
				document.clear();
			} else {
				flag = false;
				parsed = "";
				REP( i, SIZE(wrd) ) if( isalpha(wrd[i]) ) parsed += toupper( wrd[i] );
				document[parsed]++;
			}
			cin >> wrd;
		} while( true );
		
		hell:
		if( t ) cout << "\n";
		
	}
	
	return 0;
}
