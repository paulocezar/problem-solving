#include <iostream>
#include <algorithm>

using namespace std;

#define MAXC 26
#define MAXT 1001

int P[MAXC][MAXT];
int E[MAXC][MAXT];
int dp[MAXC][MAXT];
int main(){
	ios::sync_with_stdio(false);
	int Z, C, T, L;
	cin >> Z;
	while( Z-- ){
		cin >> C >> T >> L;

		for( int i = 0; i < C; i++ )
			for( int j = 0; j < T; j++ )
				cin >> P[i][j] >> E[i][j];
			
		for( int j = 0; j < T; j++ )
			dp[0][j] = P[0][j] + E[0][j];

		for( int i = 1; i < C; i++ )
			for( int j = 0; j < T; j++ ){
				dp[i][j] = dp[i-1][0]+E[i][j]+abs(P[i][j]-P[i-1][0]);
				for( int k = 1; k < T; k++ ){
					dp[i][j] = min( dp[i][j], dp[i-1][k]+E[i][j]+abs(P[i-1][k]-P[i][j]));
				}
			}
		int ans = dp[C-1][0]+L-P[C-1][0];
		for( int j = 1; j < T; j++ )
			ans = min( ans, dp[C-1][j]+L-P[C-1][j] );
		cout << ans << "\n";
	}
	return 0;
}

