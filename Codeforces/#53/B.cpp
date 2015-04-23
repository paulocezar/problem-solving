#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <cfloat>
#include <ctime> 
#include <climits>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64;

struct road{
	int a, b, c;
	bool operator <( const road& x ) const {
		return a < x.a;
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	int n, m, k;
	cin >> n >> m >> k;
	road roads[m];
	
	REP( i, m ) cin >> roads[i].a >> roads[i].b >> roads[i].c;
	sort( roads, roads+m );
	
	int64 ans = 0LL;
	while( k-- ){
		int v;
		cin >> v;
		REP( i, m ){
			if( roads[i].a > v ) break;
			if( roads[i].b < v ) continue;
			ans += (v-roads[i].a)+roads[i].c;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
