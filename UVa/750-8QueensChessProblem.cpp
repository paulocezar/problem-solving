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

struct sol_t{
	int ss[8];
	sol_t(){}
	bool operator < ( const sol_t& s ) const {
		REP( i, 8 ) if( ss[i] != s.ss[i] )
			return ss[i] < s.ss[i];
		return false;
	}
	friend ostream& operator << (ostream& o, sol_t p ){
		REP( i, 8 ) o << " " << p.ss[i]+1;
		return o;
	}
};

vector< sol_t > sol;
int now[8];
int soln;

void build( int col, int mln, int md1, int md2 ){
	if( col == 8 ){
		sol.PB( sol_t() );
		REP( i, 8 ) sol[ soln ].ss[ i ] = now[i];
		soln++;
		return;
	}
	int cand = mln, cln, line;
	while( cand > 0){
		cln = cand & -cand;
		line = __builtin_popcount( cln-1 );
		if( (md1 & (1<<(line+col))) && (md2 & (1<<(line-col+7))) ){
			now[ col ] = line;
			build( col+1, mln ^ cln, md1 ^ (1<<(line+col)), md2 ^ (1<<(line-col+7))  );
		}
		cand -= cln;
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	soln = 0; sol.clear();
	build( 0, (1<<8)-1, (1<<15)-1, (1<<15)-1 );
	
	int t, x, y;
	cin >> t;
	while( t-- ){
		cin >> x >> y; x--, y--;
		
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		
		int cc = 0;
		REP( i, soln ) if( sol[i].ss[y] == x ){
			++cc;
			if( cc > 9 ) cout << cc;
			else cout << " " << cc;
			cout << "     ";
			cout << sol[i] << "\n";
		}
		if( t ) cout << "\n";
	}
	
	return 0;
}




















