#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<int64_t>>;

const int MOD = 1e9 + 9;

int ax[128][128];

void mult(matrix& res, matrix& a, matrix& b) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ax[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        ax[i][j] += (a[i][k] * b[k][j]) % MOD;
        ax[i][j] %= MOD;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i][j] = ax[i][j];
    }
  }
}

int base[16][16];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64_t s;
  int m, d;

  cin >> s >> m >> d;

  for (int sum = 1; sum <= m; ++sum) {
    for (int last = 1; last <= m; ++last) {
      base[sum][last] = 0;
      for (int prev = max(1, last-d); prev <= min(m, last+d); ++prev) {
        if ((sum-last) >= prev) {
          base[sum][last] += base[sum-last][prev];
          base[sum][last] %= MOD;
        }
      }
      if (sum == last) {
        base[sum][last]++;
        base[sum][last] %= MOD;
      }
    }
  }

  int ans = 0;

  if (s > m) {
    s -= m;

    matrix res, tr;
    int sz = m * m;

    res.resize(sz); tr.resize(sz);

    for (auto &r : res) r.assign(sz, 0);
    for (auto &r : tr) r.assign(sz, 0);

    for (int i = 0; i < sz; ++i) res[i][i] = 1;

    for (int i = m; i < sz; ++i)
      tr[i][i-m] = 1;

    for (int last = 1; last <= m; ++last) {
      for (int prev = max(1, last-d); prev <= min(m, last+d); ++prev) {
        tr[last-1][(last-1)*m + (prev-1)] = 1;
      }
    }

    while (s > 0) {
      if (s & 1) mult(res, res, tr);
      mult(tr, tr, tr);
      s >>= 1;
    }

    for (int last = 1; last <= m; ++last) {
      for (int j = 0; j < sz; ++j) {
        ans += (res[last-1][j] * base[m-(j/m)][(j%m)+1]) % MOD;
        ans %= MOD;
      }
    }

  } else {
    for (int last = 1; last <= m; ++last) {
      ans += base[s][last];
      ans %= MOD;
    }
  }

  cout << ans << "\n";

  return 0;
}
