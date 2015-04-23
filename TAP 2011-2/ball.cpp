#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1001

vector< int > stack[MAXN];
vector<bool> seen[MAXN];
vector<int> dp[MAXN];

int N;

int solve( int i, int j ){
	if( i == N && j == N ) return 0;
	if( i == N ) return solve( i-1, j );
	if( j > i ) return 0;
	if( seen[i][j] ) return dp[i][j];
	seen[i][j] = true;
	dp[i][j] = solve( i-1, j );
	dp[i][j] = max( dp[i][j], stack[i][j]+solve(i+1,j+1) );
	return dp[i][j];
}

int main(){
	ios::sync_with_stdio(false);
	
	for( int i = 0; i < MAXN; i++ ){ stack[i].resize(i+1); dp[i].resize(i+1); seen[i].resize(i+1); }
	
	while( cin >> N && N ){
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j <= i; j++ ){
				seen[i][j] = false;
				cin >> stack[i][j];
				if( i-1 >= j ) stack[i][j] += stack[i-1][j];
			}
		}
		cout << solve( N-1, 0 ) << "\n";	
	}	
	return 0;
}