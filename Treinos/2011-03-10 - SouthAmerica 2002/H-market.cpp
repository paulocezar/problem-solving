#include <cstdio>
#include <cstdlib>

template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }

using namespace std;

#define MAXN  100001
#define MAXM 101

#define INF MAXN*MAXM*2

double dp[2][MAXM];
double cost[MAXN];
int id[MAXN];
int buy[MAXM];


int main(){
	
	int M, N;
	int old, cur;
	
	scanf("%d %d", &M, &N );
	while( M+N ){
	
		for( int i = 0; i < M; i++ ) scanf("%d", buy+i );
		for( int i = 0; i < N; i++ ) scanf("%d %lf", id+i, cost+i );
		
		for( int i = 0; i < M; i++ ) dp[0][i] = double( INF );
		
		old = 0;
		cur = 1;
		
		for( int i = 0; i < N; i++ ){
		
			for( int j = 0; j < M; j++ ){
				if( id[i] == buy[j] ){
					dp[cur][j] = MIN( dp[old][j], (j?dp[old][j-1]:0.0) + cost[i] );
				} else dp[cur][j] = dp[old][j];
			}
			old = !old;
			cur = !cur;
			
		}
		
		if( dp[old][M-1] == double( INF ) ) puts("Impossible");
		else printf("%.02lf\n", dp[old][M-1] );
		
		scanf("%d %d", &M, &N );
	}
	
	return 0;
}
