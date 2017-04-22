#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int DIV = 8;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string num;
  cin >> num;

  int dp[2][DIV];
  memset(dp, 0, sizeof(dp));

  dp[0][0] = 1;

  int cur = 1, prev = 0;

  for (int p = n-1; p >= 0; --p) {
    for (int m = 0; m < DIV; ++m) {
      dp[cur][m] = (dp[prev][m] + dp[prev][(10*m + int(num[p]-'0'))%DIV]) % MOD;
    }
    cur = 1 - cur;
    prev = 1 - prev;
  }

  dp[prev][0] = (dp[prev][0] - 1 + MOD) % MOD;
  cout << dp[prev][0] << "\n";

  return 0;
}
