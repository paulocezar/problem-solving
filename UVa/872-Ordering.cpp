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
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char gr[30][30], ans[30];
bool seen[30], print;
vector< char > verts;

bool ok( int at, int who ){
	REP( i, at ) if( gr[who][ ans[i]-'A' ] ) return false;
	return true;
}

void play( int at ){
	if( at == SIZE(verts) ){
		cout << ans[0];
		FOR( i, 1, at-1 ) cout << " " << ans[i];
		cout << "\n";
		print = true;
		return;
	}
	REP( i, SIZE(verts) ) if( !seen[ verts[i]-'A' ] && ok( at, verts[i]-'A' ) ){
		seen[ verts[i]-'A' ] = true;
		ans[ at ] = verts[i];
		play( at+1 );
		seen[ verts[i]-'A' ] = false;
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t; char u, v, trsh;
	string linea, lineb;
	
	cin >> t; cin.ignore();
	while( t-- ){
		
		cin.ignore();
		getline( cin, linea );
		getline( cin, lineb );
		
		istringstream in( linea );
		verts.clear();
		while( in >> v ) verts.PB( v );
		sort( ALL( verts ) );
		
		FILL( gr, 0 );
		istringstream inb( lineb );
		while( inb >> u >> trsh >> v ){
		gr[u-'A'][v-'A'] = 1;
		}
		
		FILL( seen, false );
		print = false;
		play( 0 );
		if( !print ) cout << "NO\n";
		if( t ) cout << "\n";
	}
	
	return 0;
}




















