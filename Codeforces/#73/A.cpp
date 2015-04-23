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
#include <utility>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

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
	
	map< string, int > id;
	id[ "C" ] = 0;
	id[ "C#" ] = 1;
	id[ "D" ] = 2;
	id[ "D#" ] = 3;
	id[ "E" ] = 4;
	id[ "F" ] = 5;
	id[ "F#" ] = 6;
	id[ "G" ] = 7;
	id[ "G#" ] = 8;
	id[ "A" ] = 9;
	id[ "B" ] = 10;
	id[ "H" ] = 11;
		
	string x[3];
	cin >> x[0] >> x[1] >> x[2];
	sort( x, x+3 );
	
	string ans;
	try{
			do{
				
				int xy;
				if( id[x[0]] < id[x[1]] ) xy = id[x[1]] - id[x[0]];
				else xy = 12-id[x[0]] + id[x[1]];
				
				int yz;
				if( id[x[1]] < id[x[2]] ) yz = id[x[2]] - id[x[1]];
				else yz = 12-id[x[1]] + id[x[2]];
				
				if( xy == 4  && yz == 3 ) throw (ans = "major");
				else if( xy == 3 && yz == 4 ) throw (ans = "minor");

		} while( next_permutation( x, x+3 ) );
	} catch(...){
		cout << ans << "\n";
		return 0;
	}
	cout << "strange\n"; 

 	return 0;
}

































