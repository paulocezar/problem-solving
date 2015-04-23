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

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char gr[27][27];
char nd[27];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	char u;
	string line, neig;
	
	while( true ){
		cin >> line;
		if( line[0] == '#' ) break;
		
		REP( i, SIZE(line) ) if( line[i] == ':' || line[i] == ';' ) line[i] = ' ';
		FILL( gr, 0 ); FILL( nd, 0 );
		
		istringstream in( line );
		while( in >> u >> neig ){
			REP( i, SIZE(neig) ){
				gr[u-'A'][neig[i]-'A'] = gr[neig[i]-'A'][u-'A'] = 1;
				nd[u-'A'] = nd[neig[i]-'A'] = 1;
			}
		}
		string perm = "";
		for( u = 'A'; u <= 'Z'; u++ ) if( nd[u-'A'] ) perm += u;
		
		string anss = "";
		int ans = INF;
		do{
		
			int curmx = 0;
			REP( i, SIZE(perm) ) FOR( j, i, SIZE(perm) ) if( gr[perm[i]-'A'][perm[j]-'A'] ) curmx = MAX( curmx, j-i );
			if( curmx < ans ){
				ans = curmx;
				anss = perm;
			}
		
		} while( next_permutation( perm.begin(), perm.end() ) );
		
		REP( i, SIZE(perm) ) cout << anss[i] << " ";
		cout << "-> " << ans << "\n";
		
	}
	
	return 0;
}




















