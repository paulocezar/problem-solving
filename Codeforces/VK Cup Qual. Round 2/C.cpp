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



int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	const int ALPH = 'z'-'a'+1;
	
	int k;
	cin >> k;
	
	string s;
	cin >> s;
	
	vector< int > occ[ALPH];
	
	int len = SIZE(s);
	REP( i, len ){
		int now = s[i]-'a';
		int pos = i+1;
		REP( j, k ){ occ[now].PB( pos ); pos += len; }
	}
	
	REP( i, ALPH ) sort( ALL(occ[i]) );
	
	int n, p;
	char c;
	cin >> n;
	while( n-- ){
		cin >> p >> c;
		occ[c-'a'].erase( (occ[c-'a'].begin()+(p-1)) );
	}
	
	vector< pair<int,char> > ans;
	REP( i, ALPH ){
		REP( j, SIZE(occ[i]) ){
			ans.PB(  MP( occ[i][j], char(i+'a') ) );
		}
	}
	
	sort( ALL(ans) );
	REP( i, SIZE(ans) ) cout << ans[i].second; cout << "\n";
	
	return 0;
}

























