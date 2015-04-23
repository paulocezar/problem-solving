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

char fxd[222*55];

void fix( string& s ){
	int len = SIZE(s);
	if( s[len-1] != '/' ){ s += "/"; len++; }
	
	int pos = 0;
	
	REP( i, len ) if( s[i] == '.' ){
		if( i+2 < len && s[i+1] == '.' && s[i+2] == '/' ){
			pos--;
			while( fxd[pos-1] != '/' ) pos--;
			i+=2;
		} else fxd[pos++] = s[i];
	} else fxd[pos++] = s[i];
	
	s = "";
	REP( i, pos ) s += fxd[i];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	string cmd, nw, cur = "/";
	
	while( n-- ){
		cin >> cmd;
		if( cmd == "pwd" ){
			cout << cur << "\n";
		} else {
			cin >> nw;
			if( nw[0] == '/' ){
				cur = nw;
			} else {
				cur += nw;
			}
			fix(cur);
		}
	}
		
	return 0;
}

























