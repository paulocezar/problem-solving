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
#include <bitset>

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
	
	string num;
	cin >> num;
	
	reverse( num.begin(), num.end() );
	
	while( *(num.end()) == '0' ) num.erase( num.end() );
	
	int i = 0, op = 0;
	while( i < SIZE(num) ){
		if( i == SIZE(num)-1 ) break;
		if( num[i] == '0' ){
			op++;
		} else {
			op += 2;
			int car = 1;
			int j = i+1;
			while( j < SIZE(num) && car ){
				if( num[j] == '1' ) num[j] = '0';
				else{ num[j] = 1; car = 0; }
				j++;
			}
			if( car ) num += '1';
		}
		while( *(num.end()) == '0' ) num.erase( num.end() );
		i++;
	}
	cout << op << "\n";
	
	
 	return 0;
}

































