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

#define MAXX 80*100
pair<int,int> rem[MAXX];

int main( int argc, char* argv[] ){
	
	int N, M;
	char linha[100];
	
	scanf("%d %d", &N, &M );
	while( N+M ){
		getchar();
		
		char emot[N][20];
		int sz[N];
		REP( i, N ){
			gets( emot[i] );
			sz[i] = strlen( emot[i] );
		}
		
		int ans = 0;
		REP( j, M ){
			gets( linha );
			int lnsz = strlen( linha );
			//cout << "linha: " << linha << "." << endl;
			int rptr = 0;
			REP( i, N ){
				REP( k, lnsz-sz[i]+1 ){
					if( strncmp( emot[i], linha+k, sz[i] ) == 0 ){
						rem[rptr].first = k+sz[i];
						rem[rptr++].second = k;
					}
				}
			}
			if( rptr ){
				sort( rem, rem+rptr );
				ans++;
				int end = rem[0].first;
				int cr = 1;
				while( cr < rptr ){
					while( cr < rptr && rem[cr].second < end ) cr++;
					if( cr < rptr ){
						ans++;
						end = rem[cr].first;
					}
				}
			}
			
		}
		printf("%d\n", ans );
		
		scanf("%d %d", &N, &M );
	}
	
	return 0;
}




















