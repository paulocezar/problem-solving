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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 MOD;

vector< int64 > mult( vector<int64>&a, vector<int64>&b ){
	vector< int64 > ret( a.size() );
	int dim = sqrt( a.size() );
	REP( i, SIZE(a) ){
		ret[i] = 0;
		REP( j, dim ) ret[i] = (ret[i] + ( a[(i/dim)*dim+j]*b[(dim*j)+(i%dim)] )%MOD )%MOD;
	}
	return ret;
}

int64 getMod( const string& x ){
	int64 a = 0LL;
	REP( i, SIZE(x) ) a = ( (a * 10LL)%MOD + int64(x[i]-'0') ) % MOD;
	return a;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	
	string as, bs, ns;
	int64 a, b;
	vector<int64> tr(4), p(4);
	
	while( t-- ){
	
		cin >> as >> bs >> ns >> MOD;
		
		a = getMod( as );
		b = getMod( bs );
				
		vector<int> n;     
		RREP( i, SIZE(ns) ) n.pb( ns[i]-'0' );
		
		while( SIZE(n) && n[SIZE(n)-1] == 0 ) n.pop_back();
		
		tr[0] = 1; tr[1] = 0; 
		tr[2] = 0; tr[3] = 1;
		
		p[0] = a; p[1] = 1;
		p[2] = 0; p[3] = 1;
		
		while( SIZE(n) > 0 ){
			//RREP( i, SIZE(n) ) cout << n[i]; cout << "\n";
			if( n[0] & 1 ) tr = mult( p, tr );
			p = mult( p, p );

			int nxt, cr = 0;
			RREP( i, SIZE(n) ){
				nxt = 10*cr + n[i];
				cr = nxt&1;
				n[i] = nxt/2;
			}
			while( SIZE(n) && n[SIZE(n)-1] == 0 ) n.pop_back();
		}
		
		cout << (tr[0] + (tr[1]*b)%MOD ) % MOD << "\n";
	}
	
	return 0;
}
