#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 17;

unordered_map<int, int> dp[MAXN];

int solve(int n, int k) {
  if (k == 0) return 1;
  else if (n == 1 && k == 1) return 0;
  else if (n < 0 || k < 0) return 0;

  if (dp[n].count(k)) return dp[n][k];

  int res = solve(n, k-1);
  res = (res + solve(n-1, k)) % MOD;
  res = (res - solve(n-1, k-n) + MOD) % MOD;
  res = (res + MOD) % MOD;

  return (dp[n][k] = res);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << "\n";

  return 0;
}
