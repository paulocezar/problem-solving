#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MNNN = 20;
const int MXXX = 1 << MNNN;

unordered_map<int, unordered_map<int,int>> cache[MXXX];

int solve(int cur, int xr, int need) {
  if (!need) return xr ? 1 : 0;
  if (!cur) return 0;

  if (cache[cur][xr].count(need)) {
    return cache[cur][xr][need];
  }

  return cache[cur][xr][need] =
    (solve(cur-1, xr, need) + solve(cur-1, xr^cur, need-1)) % MOD;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  if (m <= MNNN) {
    int mx = 1 << m;
    int res = 0;
    if (n < mx) res = solve(mx-1, 0, n);
    int64 f = 1LL;
    for (int i = 2; i <= n; ++i) {
      f *= int64(i); f %= MOD;
    }
    res = (int64(res) * f) % MOD;
    cout << res << "\n";
  } else {
    cout << "0\n";
  }

  return 0;
}
