#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dp[1<<20], N;

int rev(int x) {
    int ans = 0;
    while (x) {
        ans = 10*ans + (x%10);
        x /= 10;
    }
    return ans;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N;
        dp[N] = 1;
        for (int i = N-1; i >= 1; --i) {
            dp[i] = 1 + dp[i+1];
            int rc = rev(i);
            if (rc > i && rc <= N) dp[i] = min(dp[i], 1 + dp[rc]);
        }
        cout << "Case #" << tc << ": " << dp[1] << "\n";
    }

	return 0;
}

















