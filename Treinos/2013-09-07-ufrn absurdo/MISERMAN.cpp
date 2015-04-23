#include <iostream>
#include <algorithm>

#define MAXN 128

using namespace std;

int dp[MAXN], a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) cin >> dp[i];
    
    for (int i = 1; i < n; ++i ) {
         for (int j = 0; j < m; ++j) {
             cin >> a[j];
             a[j] += min(j ? dp[j-1] : 1<<30, min(dp[j], (j<(m-1)) ? dp[j+1] : 1<<30));
         }
         for (int j = 0; j < m; ++j) dp[j] = a[j];
    }
    
    int ans = 1<<30;
    for (int i = 0; i < m; ++i)
         ans = min(ans, dp[i]);
           
    cout << ans << "\n";
    
    return 0;    
}
