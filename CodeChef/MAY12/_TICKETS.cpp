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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXM 501

int gr[MAXM][MAXM];
int dbl[MAXM], pr[MAXM];

int main( int argc, char* argv[] ){
	
	int t = next_int();
	while( t-- ){
		int N = next_int();
		int M = next_int();
		
		vector< pair<int,int> > patron;
		set< int > plates;
		REP( i, M ){
			dbl[i] = 0;
			int a = next_int(), b = next_int();
			
			plates.insert( a );
			plates.insert( b );
			
			patron.PB( MP(min(a,b), max(a,b)) );
			
		}
		
		int twos = 0;
		
		REP( i, M ) FOR( j, i+1, M-1 ){
			
			if( patron[i] == patron[j] ){
				gr[i][j] = 1;
				gr[j][i] = 1;
				
				twos++;
				
				dbl[i]++;
				dbl[j]++;
				
				pr[i] = j;

				
			} else if( patron[i].first == patron[j].first ){
				gr[i][j] = 1;
				gr[j][i] = 1;
		 	} else if( patron[i].second == patron[j].second ){
				gr[i][j] = 1;
				gr[j][i] = 1;
			} else if( patron[i].first == patron[j].second ){
				gr[i][j] = 1;
				gr[j][i] = 1;
			} else if( patron[i].second == patron[j].first ){
				gr[i][j] = 1;
				gr[j][i] = 1;
			} else { 
				gr[i][j] = INF;
				gr[j][i] = INF;
			}
		}
		REP( i, M ) gr[i][i] = 0;
		
		if( twos < 2 ){
			printf("%d\n", min( M, SIZE(plates)) );
		} else {
			
			REP( k, M ) if( dbl[k] > 1 ){
				puts("2");
				goto hell;
			}
			
			
			REP( k, M ) REP( i, M ) REP( j, M )
				gr[i][j] = min( gr[i][j], gr[i][k]+gr[k][j] );
			
			
			
			int ans = INF;
			REP( i, M ) FOR( j, i+1, M-1 ) if( dbl[i] && dbl[j] && (pr[i] != j) ){
				ans = min( ans, gr[i][j] );
			}
			
			if( ans == INF ) printf("%d\n", min(M, SIZE(plates)) );
			else printf("%d\n", min( min(N,M), ans+2) );
			
		}
	hell:;
		
		
	}
	
	return 0;
}

























