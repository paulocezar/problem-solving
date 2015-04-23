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

bool best( int64 PA, int64 WA, int64 PB, int64 WB ){
	return (((PA<PB)&&(WA<=WB)) || ((WA<WB)&&(PA<=PB)));
}

#define MXXX 10000001
int64 P[MXXX], W[MXXX];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	FOR( tc, 1, t ){
		
		int64 N, M, Pold, Wold, K, A, B, C, D;
		cin >> N >> P[0] >> W[0] >> M >> K >> A >> B >> C >> D;
		
		A%=M;  B%=M;
		C%=K;  D%=K;
		map< int64, map< int64, int64> > seen;
		
		seen[ P[0] ][ W[0] ] = 0;
		
		int64 i = 1;	
		bool cycled = false;
		while( i < N ){
						
			Pold = P[i-1]%M;
			Wold = W[i-1]%K;

			P[i] = ((((A*Pold)%M)+B)%M)+1LL;
			W[i] = ((((C*Wold)%K)+D)%K)+1LL;
			
			if( seen[ P[i] ].find( W[i] ) != seen[ P[i] ].end() ){
				
				int64 x;
				for( x = 0; x < seen[ P[i] ][ W[i] ]; x++ ){
					seen[ P[x] ][ W[x] ] = 1;
				}
				N -= x;
				int64 rept = N/(i-x+2);
				N %= (i-x+2); N--; if( N < 0 ) N = 0;
				while( x < i ){
					seen[ P[x] ][ W[x] ] = 1;
					if( N ){ seen[ P[x] ][ W[x] ]++; N--; }
					seen[ P[x] ][ W[x] ] += rept;
					x++;
				}
				
				cycled = true;
				break;
			}
			seen[P[i]][W[i]] = i;
			i++;
		}
		
		if( !cycled ) for( int64 x = 0; x < i; x++ ) seen[P[x]][W[x]] = 1;
		
		int64 a = 0, b = 0;
		for( int64 x = 0; x < i; x++ ){
			//cout << P[x] << " " << W[x];
			int64 bst = 0, wst = 0;
			for( int64 j = 0; j < i; j++ ) if( x != j ){
				if( best(P[x],W[x],P[j],W[j]) ) bst++;
				if( best(P[j],W[j],P[x],W[x]) ) wst++;
			}
			if( wst == 0 ){ //cout << " bargain";
			b+=seen[P[x]][W[x]]; }
			if( bst == 0 ){ //cout << " terrible";
			a+=seen[P[x]][W[x]]; }
			//cout << "\n";
		}
		cout << "Case #" << tc << ": " << a << " " << b << "\n";
	}
	
	return 0;
}




















