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

int N, dp[10][1<<9];
int fuckit[10];

int solve( int prev, int aval ){
	if( !aval ) return 1;
	int &ret = dp[prev][aval];
	
	if( ret == -1 ){
		ret = 0;
		REP( i, N ) if( aval & (1<<i) ){
			if( !(fuckit[prev] & (1<<i)) ){
				//cout << prev << " " << aval << " put " << i << endl;
				ret += solve( i, aval ^ (1<<i) );
			}
		}	
	}
	
	return ret;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, u, v;
	string name;
	cin >> t;
	fuckit[9] = 0;
	int tc = 1;
	
	while( t-- ){
		
		cin >> N;
		map< string, int > id;
		REP( i, N ) fuckit[i] = 0;
		
		REP( i, N ){
			cin >> name;
			if( !id.count(name) ){
				u = SIZE(id);
				id[name] = u;
			}
			u = id[name];
			int die = 0;
			cin >> die;
			while( die-- ){
				cin >> name;
				if( !id.count(name) ){
					v = SIZE(id);
					id[name] = v;
				}
				v = id[name];
				fuckit[u] |= (1<<v);
				fuckit[v] |= (1<<u);
			}
		}
		
		REP( i, N ) REP( j, 1<<N ) dp[i][j] = -1;
		dp[9][(1<<N)-1] = -1;
		cout << "Teste #" << tc++ << ": " << solve(9, (1<<N)-1 ) << "\n";
		
	}
	
	return 0;
}

























