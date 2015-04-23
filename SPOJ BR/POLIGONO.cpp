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

#define MAXN 10001
set<int> points;
int point[MAXN];
int N, total;

bool can( int n ){
	if( total % n ) return false;
	int i = 0;
	int side = total/n;
	while( i < N && point[i] < side ){
		int nd = point[i];
		while( points.find( nd ) != points.end() ){
			nd += side;
			if( nd >= total ) return true;
		}
		i++;
	}
	return false;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int x;
	cin >> N; point[0] = 0;
	while( N ){
		
		total = 0;
		points.clear(); points.insert( 0 );
		REP( i, N ){ cin >> x; total += x; point[i+1] = total; points.insert(total); }
		
		int ans = N;
		while( ans >= 3 && !can(ans) ) ans--;
		if( ans == 2 ) ans = N+1;
		cout << N-ans << "\n";
		
		cin >> N;
	}
	
	return 0;
}




















