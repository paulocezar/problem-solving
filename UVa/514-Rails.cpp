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
#include <stack>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1001
int a[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int n;
	while( cin >> n && n ){
		
		cin >> a[0];
		while( a[0] ){
			FOR( i, 1, n ) cin >> a[i];
			
			stack< int > station;
			int cur = 1;
			int pos = 0;
			bool stop = false;
			
			while( !stop ){
				while( station.empty() || station.top() != a[pos] ){
					if( cur > n ){ cout << "No\n"; stop = true; break; }
					station.push( cur++ );
				}
				
				if( !stop ){
					station.pop();
					pos++;
					if( pos == n ){ cout << "Yes\n", stop = true; }
				}
			}
			
			cin >> a[0];
		}
		cout << "\n";
		
	}
	
	return 0;
}





