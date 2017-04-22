#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 6;

int g[MAXN][MAXN];

int tri[MAXN], id[MAXN];

inline bool is_tri(int u, int v, int w) {
  return (g[u][v] && g[u][w] && g[v][w]);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    id[i-1] = i;
    for (int j = 1; j <= n; ++j) {
      cin >> g[i][j];
    }
  }

  int total_tri = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      for (int k = j+1; k <= n; ++k) {
        if (is_tri(i, j, k)) {
          ++tri[i], ++tri[j], ++tri[k];
          ++total_tri;
        }
      }
    }
  }

  auto l = [](int a, int b) -> bool {
    if (tri[a] != tri[b]) return tri[a] > tri[b];
    return a < b;
  };

  int cur_n = n;

  while (true) {

    sort(id, id+cur_n, l);
    while (cur_n && tri[id[cur_n-1]] == 0) --cur_n;

    if (!cur_n) { cur_n = 1; break; }

    if (total_tri * (cur_n - 1) > (total_tri - tri[id[cur_n-1]]) * cur_n)
      break;

    --cur_n;

    for (int j = 1; j <= n; ++j) if (j != id[cur_n]) {
      for (int k = j+1; k <= n; ++k) if (k != id[cur_n]) {
        if (is_tri(id[cur_n], j, k)) {
          --total_tri;
          --tri[id[cur_n]], --tri[j], --tri[k];
        }
      }
    }
  }

  cout << cur_n << "\n";
  for (int i = 0; i < cur_n; ++i) {
    cout << id[i] << " \n"[((i+1)==cur_n) ? 1 : 0];
  }

  return 0;
}
