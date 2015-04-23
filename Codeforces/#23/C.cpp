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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct box_t{
	int64 oranges, apples;
	int id;
	bool operator < (const box_t& a) const{
		if( oranges != a.oranges ) return oranges < a.oranges;
		if( apples != a.apples ) return apples < a.apples;
		return id < a.id;
	}
};

#define MAXN 100000
box_t box[2*MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		int n;
		cin >> n;
		int64 apples = 0, oranges = 0;
		
		for( int i = 0; i < 2*n-1; i++ ){
			cin >> box[i].apples >> box[i].oranges;
			box[i].id = i+1;
			apples += box[i].apples;
			oranges += box[i].oranges;
		}
		sort( box, box+2*n-1 );
		
		int64 a[2], o[2];
		FILL( a, 0 ); FILL( o, 0 );
		
		for( int i = 0; i < 2*n-1; i++ ){
			a[i&1] += box[i].apples;
			o[i&1] += box[i].oranges;
		}

		if( n > 1 ){
			a[1] += box[2*(n-1)].apples;
			o[1] += box[2*(n-1)].oranges;
		}
		
		if( 2LL*a[0] >= apples && 2LL*o[0] >= oranges ){
			cout << "YES\n";
			bool fl = false;
			for( int i = 0; i < 2*n-1; i++ )
				if( !(i&1) ){
					if( fl ) cout << " ";
					cout << box[i].id;
					fl = true;
				}		
			cout << "\n";
		} else if( 2LL*a[1] >= apples && 2LL*o[1] >= oranges ){
			cout << "YES\n";
			for( int i = 0; i < 2*n-1; i++ )
				if( i&1 ) cout << box[i].id << " ";
			cout << box[2*n-2].id << "\n";
		} else cout << "NO\n\n";
		
	}
		
	return 0;
}




















