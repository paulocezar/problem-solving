#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int has[1<<10];
int64 dist[1<<10][1<<10];

vector<pair<int,int>> gr[1<<10];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  int all = (1<<K) - 1;

  for (int i = 1; i <= N; ++i) {
    int Ti; cin >> Ti;
    has[i] = 0;
    while (Ti--) {
      int v; cin >> v;
      has[i] |= (1<<(v-1));
    }
  }

  while (M--) {
    int u, v, c;
    cin >> u >> v >> c;
    gr[u].push_back(make_pair(v, c));
    gr[v].push_back(make_pair(u, c));
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= all; ++j) {
      dist[i][j] = -1LL;
    }
  }

  dist[1][has[1]] = 0LL;
  priority_queue<pair<int64,int>> q;
  q.push(make_pair(0LL, (1<<K) | has[1]));

  while (!q.empty()) {
    int64 dd = -q.top().first;
    int u = q.top().second; q.pop();
    int fishes = u & all; u >>= K;

    for (auto &w : gr[u]) {
      int v = w.first;
      int64 nd = dd + w.second;
      int nf = fishes | has[v];
      if ((dist[v][nf] == -1LL) || (nd < dist[v][nf])) {
        dist[v][nf] = nd;
        q.push(make_pair(-nd, (v<<K) | nf));
      }
    }
  }

  int64 ans = -1LL;
  for (int bc = 0; bc <= all; ++bc) {
    for (int sc = 0; sc <= all; ++sc) {
      if ((bc | sc) != all) continue;
      if ((dist[N][bc] == -1LL) || (dist[N][sc] == -1LL)) continue;
      int64 cur = max(dist[N][bc], dist[N][sc]);
      if ((ans == -1LL) || (cur < ans)) ans = cur;
    }
  }
  cout << ans << "\n";

  return 0;
}
