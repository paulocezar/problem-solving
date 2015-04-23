#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t ,n, k, w, v;

int sum[30010];
int dp[30010][2];

int solve(int i, int k){
	if(k == 0) return dp[i][k] = 0;
	if(n-i+1 <= k*w) return dp[i][k] = sum[n] - sum[i-1];
	if(dp[i][k] != -1) return dp[i][k];
	
	return dp[i][k] = max( sum[i+w-1] - sum[i-1] + solve(i+w, k-1), solve(i+1, k) );
}

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	
	while(t--){
		cin >> n >> k >> w;
		sum[0] = 0; dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> v;
			sum[i] = sum[i-1] + v;
			dp[i][0] = 0;
		}
		int cur = 1, old = 0;
		for(int j = 1; j <= k ; j++){
			for(int i = n; i >= 0; i--){
				if( n-i+1 <= j*w ) dp[i][cur] = sum[n]-sum[i-1];
				else dp[i][cur] = max( sum[i+w-1]-sum[i-1]+dp[i+w][old], dp[i+1][cur] );
			}
			old = !old;
			cur = !cur;
		}
		cout << dp[0][old] << "\n";
	}
	return 0;
}
