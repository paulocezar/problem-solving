#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 dp[2][1<<14];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        vector<int64> el(n);
        for (auto &x : el) cin >> x;
        
        memset(dp,0,sizeof(dp));
        int old = 0, cur = 1;
        
        for (int t = 2; t <= n; t+=2) {
            for (int i = 0, j = t-1; j < n; ++i, ++j) {
                dp[cur][i] = max(el[i] + dp[old][i+1],
                             max(el[i] + dp[old][i+2],
                             max(el[j] + dp[old][i+1],
                                 el[j] + dp[old][i]  )));
                
            }
            old = 1-old;
            cur = 1-cur;
        }
        cout << dp[old][0] << "\n";
    }

	return 0;
}

















