#include <bits/stdc++.h>

using namespace std;

template <typename T, size_t N, size_t M>
using matrix = array<array<T, M>, N>;

const int MAXN = 20;

matrix<int64_t, (1<<MAXN), MAXN> dp;
array<vector<int>, MAXN> gr;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int all = (1<<n) - 1;

  int64_t total{0};
  for (int can_use = 1; can_use <= all; ++can_use) {
    for (int u = 0; u < n; ++u) {
      if (can_use & (1 << u)) continue;
      for (int v : gr[u]) if (can_use & (1<<v)) {
        dp[can_use][u] += 1 + dp[can_use ^ (1<<v)][v];
      }
      if ((can_use ^ (1<<u)) == all) total += dp[can_use][u];
    }
  }

  cout << total << "\n";

  return 0;
}
