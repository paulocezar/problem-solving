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

pair< char, char > check( string& wrd ){
	int N = SIZE(wrd);
	if( N >= 4 && wrd[N-4] == 'l' && wrd[N-3] == 'i' && wrd[N-2] == 'o' && wrd[N-1] == 's' )
		return MP( 'M', 'A' );
	if( N >= 5 && wrd[N-5] == 'l' && wrd[N-4] == 'i' && wrd[N-3] == 'a' && wrd[N-2] == 'l' && wrd[N-1] == 'a' )
		return MP( 'F', 'A' );
	if( N >= 3 && wrd[N-3] == 'e' && wrd[N-2] == 't' && wrd[N-1] == 'r' )
		return MP( 'M', 'N' );
	if( N >= 4 && wrd[N-4] == 'e' && wrd[N-3] == 't' && wrd[N-2] == 'r' && wrd[N-1] == 'a' )
		return MP( 'F', 'N' );
	if( N >= 6 && wrd[N-6] == 'i' && wrd[N-5] == 'n' && wrd[N-4] == 'i' && wrd[N-3] == 't' && wrd[N-2] == 'i' && wrd[N-1] == 's' )
		return MP( 'M', 'V' );
	if( N >= 6 && wrd[N-6] == 'i' && wrd[N-5] == 'n' && wrd[N-4] == 'i' && wrd[N-3] == 't' && wrd[N-2] == 'e' && wrd[N-1] == 's' )
		return MP( 'F', 'V' );	
	return MP('X', 'X');
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	bool ok = true;
	
	string word;
	string gen = "";
	string wut = "";
	while( cin >> word ){
		pair<char,char> an = check( word );
		gen += an.first;
		wut += an.second;
	}
	
	if( gen[0] == 'M' || gen[0] == 'F' ){
		FOR( i, 1, SIZE(gen)-1 ) if( gen[i] != gen[0] ){
			ok = false; goto hell;
		}
		if( SIZE(gen) > 1 ){
			int i = 0;
			while( wut[i] == 'A' ) i++;
			if( wut[i] != 'N' ){ ok = false; goto hell; }
			i++;
			while( wut[i] == 'V' && i < SIZE(wut) ) i++;
			if( i != SIZE(wut) ) ok = false; 
		}
	} else ok = false;
hell:
	if( ok ) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}




















