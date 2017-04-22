#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 13;
const int64 INF = 1e16;

int64 x[MAXN], w[MAXN], G[MAXN], SW[MAXN];

int s[2][MAXN];
int64 f[2][MAXN];

int64 cost(int k, int j) {
  return (G[j] - G[k-1]) - x[k] * (SW[j] - SW[k-1]);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> w[i];
    SW[i] = SW[i-1] + w[i];
    G[i] = G[i-1] + x[i] * w[i];
  }

  for (int i = 1; i <= n; ++i)
    f[0][i] = cost(1, i), s[0][i] = 1;

  for (int i = 2, cur = 1; i <= k; cur ^= 1, i += 1) {
    s[cur][n + 1] = n;
    for (int j = n; j >= 1; --j) {
      f[cur][j] = INF;
      for (int l = s[cur^1][j]; l <= s[cur][j + 1]; ++l)
        if (f[cur^1][l] + cost(l+1, j) < f[cur][j])
          f[cur][j] = f[cur^1][l] + cost(l+1, j),
          s[cur][j] = l;
    }
  }

  cout << f[1-(k&1)][n] << "\n";

  return 0;
}
