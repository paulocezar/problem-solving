#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 12;

int cache[MAXN][MAXN];
char cached[MAXN][MAXN];

int solve(int h, int rem) {
  if (rem == 0) return (h == 0) ? 1 : 0;
  int &res = cache[h][rem];
  if (cached[h][rem]) return res;
  cached[h][rem] = 1;
  res = solve(h+1, rem-1) % MOD;
  if (h) res += solve(h-1, rem-1);
  else res += 1;
  res %= MOD;
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int res = (solve(0, n) + MOD - 1) % MOD;
    cout << res << "\n";
  }

  return 0;
}
