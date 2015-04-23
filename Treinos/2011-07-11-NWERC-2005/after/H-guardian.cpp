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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct pupil_t{
	int heigh;
	char sex;
	string mstyle, sport;
	pupil_t( int h = 0, char s = 'M', string m = "", string sp = "" ) : heigh(h), sex(s), mstyle(m), sport(sp) {}
	bool compat( pupil_t a ){
		if( sex == a.sex ) return false;
		if( ABS(heigh - a.heigh) > 40 ) return false;
		if( mstyle != a.mstyle ) return false;
		if( sport == a.sport ) return false;
		return true;
	}
};

#define MAXN 500
pupil_t pupil[MAXN];
int graph[MAXN][MAXN], gr[MAXN], id[MAXN];
int m[MAXN], m1[MAXN];
char vis[MAXN];
int N, M;

int dfs( int a ){
	if( a < 0 ) return 1;
	if( vis[a] ) return 0;
	vis[a] = 1;
	REP( i, gr[a] ){
		if( dfs( m1[ graph[a][i] ] ) ){
			m[a] = graph[a][i];
			m1[ graph[a][i] ] = a;
			return 1;
		}
	}
	return 0;
}

int dfsExp( int a ){
	REP( i, N ) vis[i] = 0;
	return dfs( a );
}

int bipMatch(){
	REP( i, N ) m[i] = -1;
	REP( i, M ) m1[i] = -1;
	
	int ans = 0;
	int aug = 0;
	bool flag;
	do {
		ans += aug;
		aug = 0;
		flag = false;
		REP( i, N ) if( m[i] < 0 ){
			if( flag ) aug += dfs( i );
			else{ flag = true; aug += dfsExp(i); }
		}
	} while( aug );
	
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	while( t-- ){
		
		int pupils;
		cin >> pupils;
		N = M = 0;
		REP( i, pupils ){
			gr[i] = 0;
			cin >> pupil[i].heigh >> pupil[i].sex >> pupil[i].mstyle >> pupil[i].sport;
			if( pupil[i].sex == 'M' ) id[i] = N++;
			else id[i] = M++;
		}
		
		REP( i, pupils ) FOR( j, i+1, pupils-1 ) if( pupil[i].compat( pupil[j] ) ){
			if( pupil[i].sex == 'M' ) graph[ id[i] ][ gr[id[i]]++ ] = id[j];
			else graph[ id[j] ][ gr[id[j]]++ ] = id[i];
		}
		cout << pupils-bipMatch() << "\n";
	}
	
	return 0;
}




















