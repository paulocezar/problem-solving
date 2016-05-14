#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> g(N, vector<int>(N, 0));
  vector<vector<int>> res(N, vector<int>(N, 0));
  vector<vector<int>> ax(N, vector<int>(N, 0));

  while (M--) {
    int a, b;
    cin >> a >> b; a--, b--;
    g[a][b] = g[b][a] = 1;
  }

  for (int i = 0; i < N; ++i) res[i][i] = 1;

  int sep = 6;
  while (sep--) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ax[i][j] = res[i][j];
        for (int k = 0; k < N; ++k) {
          ax[i][j] |= (res[i][k] & g[k][j]);
        }
      }
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = ax[i][j];
  }

  bool ok = true;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) if (!res[i][j]) { ok = false; }

  cout << (ok ? "S\n" : "N\n");

  return 0;
}
