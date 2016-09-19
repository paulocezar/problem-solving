#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
const int64 MOD = 1e9 + 7;


int64 dp[2][MAXN];



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[0][i] = 1;
  }
  int cur = 1, old = 0;
  for (int i = 3; i <= n; ++i) {

    for (int k = 0; k <= n; ++k) {
      dp[cur][k] = dp[old][k];
      if (k) {
        dp[cur][k] += (int64(i-1) * dp[old][k-1]) % MOD;
        dp[cur][k] %= MOD;
      }
    }

    cur = 1-cur;
    old = 1-old;
  }

  for (int i = 1; i < n; ++i) {
    if (i > 1) cout << ' ';
    cout << dp[old][i];
  }
  cout << "\n";

  return 0;
}
