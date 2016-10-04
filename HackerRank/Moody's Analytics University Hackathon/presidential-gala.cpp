#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int pa[MAXN], p[MAXN];
int64 dp[2][MAXN];

vector<int> gr[MAXN];

int random_root(int nodes) {
  random_device r;
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(1, nodes);
  return uniform_dist(e1);
}

//unordered_set<int> forced, forbid;
char forced[MAXN], forbid[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) cin >> p[i];

  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for (int u = 1; u <= n; ++u) {
    sort(gr[u].begin(), gr[u].end());
    gr[u].resize(unique(gr[u].begin(), gr[u].end()) - gr[u].begin());
  }

  int root = 1;//random_root(n);

  queue<int> q;
  q.push(root);
  pa[root] = -1;

  vector<pair<int,int>> bad_edges;
  vector<int> p_ord;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    p_ord.push_back(u);
    for (int v : gr[u]) {
      if (pa[v]) {
        if (v != pa[u] && u < v) {
          bad_edges.push_back({u, v});
        }
      } else {
        pa[v] = u;
        q.push(v);
      }
    }
  }
  pa[root] = 0;
  reverse(p_ord.begin(), p_ord.end());

  int64 res = 0LL;

  int mm = 1;
  int be = bad_edges.size();
  for (int i = 0; i < be; ++i) mm *= 3;

  for (int mask = 0; mask < mm; ++mask) {
    int ax = mask;
    for (int i = 0; i < be; ++i) {
      int cr = ax % 3;
      int u = bad_edges[i].first, v = bad_edges[i].second;
      switch (cr) {
        case 0:
          forbid[u] = 1; forbid[v] = 1; break;
        case 1:
          forbid[u] = 1; forced[v] = 1; break;
        case 2:
          forced[u] = 1; forbid[v] = 1; break;
      }
      ax /= 3;
    }

    bool ok = true;
    for (auto &e : bad_edges) {
      ok = !forced[e.first] || !forced[e.second];
      if(!ok) break;
    }

    if (ok) {

      for (int i = 1; i <= n; ++i) dp[0][i] = dp[1][i] = 0LL;

      for (int u : p_ord) {

        int64 r_gettn = dp[1][u] + p[u];
        int64 r_skippn = dp[0][u];

        for (int got_pa = 0; got_pa < 2; ++got_pa) {
          int64 &cur = dp[got_pa][u];
          cur = 0LL;
          if (forced[u] && got_pa) continue;
          int64 gettn = 0LL, skippn = 0LL;

          if (!forbid[u] && !got_pa) {
            gettn = r_gettn;
          }

          if (!forced[u]) {
            skippn = r_skippn;
          }
          cur = max(skippn, gettn);
          dp[got_pa][pa[u]] += cur;
        }
      }

      res = max(res, dp[0][root]);
    }

    ax = mask;
    for (int i = 0; i < be; ++i) {
      int cr = ax % 3;
      int u = bad_edges[i].first, v = bad_edges[i].second;
      switch (cr) {
        case 0:
          forbid[u] = 0; forbid[v] = 0; break;
        case 1:
          forbid[u] = 0; forced[v] = 0; break;
        case 2:
          forced[u] = 0; forbid[v] = 0; break;
      }
      ax /= 3;
    }
  }

  cout << res << "\n";

  return 0;
}
