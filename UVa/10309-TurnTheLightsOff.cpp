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

int mn, orig[11], grid[11];
int cur;

void play( int pos ){
hell:	
	REP( i, 10 )if( grid[pos-1] & (1<<i) ){
		cur++;
		if( i ) grid[pos] ^= (1<<(i-1));
		grid[pos] ^= (1<<i);
		if( i < 9 ) grid[pos] ^= (1<<(i+1));
		if( pos < 10 ) grid[pos+1] ^= (1<<i);
	}
	if( cur > 100 ) return;
	if( pos == 10 ){
		if( grid[pos] == 0 ) mn = MIN( cur, mn );
	} else{ pos++; goto hell; }
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string name, line;
	
	cin >> name;
	while( name != "end" ){
		
		FOR( i, 1, 11 ){
			cin >> line;
			orig[i] = 0;
			REP( j, 10 ) if( line[j] == 'O' ) orig[i] |=  (1<<j);
		}
		
		orig[0] = (1<<10)-1; mn = INF;
		while( orig[0] >= 0 ){
			REP( i, 11 ) grid[i] = orig[i];
			cur = 0; play(1);
			orig[0]--;
		}
		
		if( mn != INF ) cout << name << " " << mn << "\n";
		else cout << name << " -1\n";
	
		cin >> name;
	}
	
	return 0;
}




















