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

#define MAXVAL 2222
int64 bit[MAXVAL+1];

void up( int idx ){
	idx++;
	while(idx<=MAXVAL){
		bit[idx]++; 
		idx += (idx & -idx);
	}
}

int64 get( int idx ){
	idx++;
	int64 ans = 0;
	while( idx > 0 ){
		ans += bit[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	string s;
	cin >> s;
	
	int n = SIZE(s);
	bool palin[n][n];
	
	REP( i, n ) FOR( j, i, n-1 ) palin[i][j] = false;
	
	REP( i, n ){
		palin[i][i] = true;
		up(i);
	}
	
	REP( i, n-1 ){ 
		palin[i][i+1] = (s[i]==s[i+1]);
		if( palin[i][i+1] ) up(i);
	}
	
	FOR( len, 3, n ){
		REP( i, n ){
			int j = i+len-1;
			if( j >= n ) break;
			
			palin[i][j] = ((s[i]==s[j]) && palin[i+1][j-1]);
			
			if( palin[i][j] ) up(i);
		}
	}
	
	int64 all = get(n-1);
	int64 ans = 0;	

	REP( i, n ) FOR( j, i, n-1 ) if( palin[i][j] )
		ans += ( all - get(j) );
	
	cout << ans << "\n";
	
	return 0;
}

























