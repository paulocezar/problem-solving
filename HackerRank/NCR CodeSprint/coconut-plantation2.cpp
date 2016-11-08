#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

bool seen[MAXN];
int m[MAXN], m1[MAXN], N, M;;

vector< int > gr[MAXN];

vector<vector<int>> grid, rm, cm;


int dfs(int u) {
  if (u < 0) return 1;
  if (seen[u]) return 0;
  seen[u] = true;
  for (int &v : gr[u]) {
    if (dfs(m1[v])) {
      m[u] = v;
      m1[v] = u;
      return 1;
    }
  }
  return 0;
}

int dfsExp(int u) {
  for (int i = 0; i < N; ++i) seen[i] = false;
  return dfs(u);
}


int bipMatch() {
  for (int i = 0; i < N; ++i) m[i] = -1;
  for (int i = 0; i < M; ++i) m1[i] = -1;
  int aug, ans = 0;
  do {
    aug = 0;
    bool first = true;
    for (int i = 0; i < N; ++i) if (m[i] < 0) {
      if (first) aug += dfsExp(i);
      else aug += dfs(i);
      first = false;
    }
    ans += aug;
  } while (aug);
  return ans;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int p;
  cin >> p;
  while (p--) {
    int r, c, n, m;
    cin >> r >> c >> n >> m;
    grid.resize(r);
    rm.resize(r);
    cm.resize(r);
    for (int i = 0; i < r; ++i) {
      grid[i].resize(c);
      rm[i].resize(c);
      cm[i].resize(c);
      for (int &v : grid[i]) v = 0;
    }

    while (n--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      grid[x1][y1]++;
      x2++, y2++;
      if (y2 < c) grid[x1][y2]--;
      if (x2 < r) grid[x2][y1]--;
      if (x2 < r && y2 < c) grid[x2][y2]++;
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int acm = 0;
        if (i) acm += grid[i-1][j];
        if (j) acm += grid[i][j-1];
        if (i && j) acm -= grid[i-1][j-1];
        grid[i][j] += acm;
      }
    }

    N = 0, M = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (j == 0 || (grid[i][j] >= m && grid[i][j-1] < m)) {
          gr[N++].clear();
        }
        rm[i][j] = N;
      }
    }

    for (int j = 0; j < c; ++j) {
      for (int i = 0; i < r; ++i) {
        if (i == 0 || (grid[i][j] >= m && grid[i-1][j] < m)) M++;
        cm[i][j] = M;
      }
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] >= m) {
          gr[rm[i][j]-1].push_back(cm[i][j]-1);
        }
      }
    }

    cout << bipMatch() << "\n";

  }

  return 0;
}
