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
	
	int n;
	map< string, int > type;
	type["void"] = 0;
	type["errtype"] = -1;
	
	cin >> n;
	string wut, A, B;
	
	while( n-- ){
		cin >> wut;
		if( wut[4] == 'd' ){
			
			cin >> A >> B;
			
			int i = 0, ind = 0;
			while( A[i] == '&' ) ind--, i++;
			int j = SIZE(A)-1;
			while( A[j] == '*' ) ind++, j--;
			
			string olda = A.substr( i, j-i+1 );
			
			if( type.find(olda) == type.end() || type[ olda ] < 0 ) type[ B ] = -1;
			else type[ B ] = type[ olda ] + ind;
			
		} else {
			cin >> A;
			
			int i = 0, ind = 0;
			while( A[i] == '&' ) ind--, i++;
			int j = SIZE(A)-1;
			while( A[j] == '*' ) ind++, j--;
			
			string olda = A.substr( i, j-i+1 );
			
			int hm = -1;
			if( type.find(olda) == type.end() || type[ olda ] < 0 ) hm = -1;
			else hm = type[ olda ] + ind;
			
			if( hm < 0 ){
				cout << "errtype\n";
			} else {
				cout << "void";
				while( hm-- ) cout << "*";
				cout << "\n";
			}
		}
	}
 	return 0;
}

































