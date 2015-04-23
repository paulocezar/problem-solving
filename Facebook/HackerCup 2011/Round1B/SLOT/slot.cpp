#include <map> 
#include <set> 
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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

#define ti(x) x::iterator

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 10000001LL;
int64 secret;

int getRandom(){
  secret = (secret * 5402147LL + 54321LL ) % MOD;
  return int( secret % 1000LL );
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	while( t-- ){
	
		int n;
		cin >> n;
		int gen[n];
		REP( i, n ) cin >> gen[i];
		
		bool find, find2;
		find = find2 = false;
		
		int next[10];
		REP( x, 10000001 ){
			secret = x;
			REP( i, n ) if( getRandom() != gen[i] ) goto wr;
			REP( i, 10 ) next[i] = getRandom();
			if( find ) find2 = true;
			else find = true;
			wr:
				if( find && find2 ) break;
		}
		
		if( !find ) cout << "Wrong machine\n";
		else if( find && !find2 ){
			REP( i, 10 ) cout << next[i] << " ";
			cout << "\n";
		} else cout << "Not enough observations\n";
		
	}	

	return 0;
}
