#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int LGMV = 17;
const int MAXV = 1 << LGMV;
const int MAXE = 1 << 18;

vector<int> graph[MAXV];
vector<int> tree[MAXV];

int U[MAXE], V[MAXE];
bool is_bridge[MAXE], is_articulation[MAXV];

int d_start[MAXV], d_end[MAXV], component[MAXV], idx[MAXV];

int L[MAXV], P[LGMV][MAXV];

int dfs_num, current_component;

inline int opposite(int u, int edge) {
  return (u==U[edge]?V[edge]:U[edge]);
}

inline bool same_component(int u, int v) {
  return component[u] == component[v];
}

namespace bridges {
  int find(int u, int edge_to_parent = -1) {
    component[u] = current_component;
    int lowest = d_start[u] = ++dfs_num;

    for (int edge : graph[u]) {
      int v = opposite(u, edge);
      if (!d_start[v]) {
        lowest = min(lowest, find(v, edge));
      } else if (edge != edge_to_parent) {
        lowest = min(lowest, d_start[v]);
      }
    }

    if (lowest == d_start[u] && edge_to_parent != -1) {
      is_bridge[edge_to_parent] = true;
      is_articulation[U[edge_to_parent]] = true;
      is_articulation[V[edge_to_parent]] = true;
    }

    return lowest;
  }
}

namespace bridge_tree {
  bool is_ancestor(int v, int of) {
    return (d_start[v] <= d_start[of]) && (d_start[of] <= d_end[v]);
  }
  void traverse(int u) {
    for (int i = 1; i < LGMV; ++i) {
      P[i][u] = P[i - 1][P[i - 1][u]];
    }

    d_start[u] = ++dfs_num;
    for (int v : tree[u]) {
      if (d_start[v]) continue;
      L[v] = L[u] + 1;
      P[0][v] = u;
      traverse(v);
    }
    d_end[u] = dfs_num;
  }

  int lca(int u, int v) {
    int log;
    if (L[u] < L[v]) swap(u, v);

    for (log = 1; 1 << log <= L[u]; ++log);
      log--;

    for (int i = log; i >= 0; --i) {
      if (L[u] - (1 << i) >= L[v])
        u = P[i][u];
    }

    if (u == v) return u;

    for (int i = log; i >= 0; --i) {
      if (P[i][u] != P[i][v])
        u = P[i][u], v = P[i][v];
    }

    return P[0][u];
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  dfs_num = 0, current_component = 0;

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 1; i <= m; ++i) {
    cin >> U[i] >> V[i];

    graph[U[i]].push_back(i);
    graph[V[i]].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    if (!d_start[i]) {
      current_component++;
      bridges::find(i);
    }
  }

  current_component = 0;
  for (int i = 1; i <= n; ++i) {
    if (!idx[i]) {
      queue<int> q;
      q.push(i); idx[i] = ++current_component;
      d_start[current_component] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int edge : graph[u]) {
          int v = opposite(u, edge);
          if (!is_bridge[edge] && !idx[v]) {
            idx[v] = current_component;
            q.push(v);
          }
        }
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    if (is_bridge[i]) {
      tree[idx[U[i]]].push_back(idx[V[i]]);
      tree[idx[V[i]]].push_back(idx[U[i]]);
    }
  }

  dfs_num = 0;
  for (int i = 1; i <= current_component; ++i)
    if (!d_start[i]) {
      L[i] = 1;
      P[0][i] = i;
      bridge_tree::traverse(i);
    }

  int u, v, w;
  while (q--) {
    cin >> u >> v >> w;

    bool has_path = false;

    if (same_component(u, w) && same_component(v, w)) {
      if (u == w || v == w) has_path = true;
      else if (u != v) {
        if (idx[u] == idx[v] && idx[u] != idx[w]) {
          has_path = false;
        } else if (idx[u] != idx[v] && (idx[u] == idx[w] || idx[v] == idx[w])) {
          has_path = true;
          int bad = idx[u] == idx[w] ? u : v;
          int other = idx[u] == idx[w] ? v : u;
          if (is_articulation[bad]) {
            for (int edge : graph[bad]) {
              if (is_bridge[edge]) {
                int opp = opposite(bad, edge);
                if (bridge_tree::is_ancestor(idx[opp], idx[other])) {
                  has_path = false;
                  break;
                }
              }
            }
          }
        } else {
          u = idx[u], v = idx[v], w = idx[w];

          if (u == v && u == w) has_path = true;
          else {
            using bridge_tree::lca;
            using bridge_tree::is_ancestor;

            has_path = (is_ancestor(w, u) || is_ancestor(w, v)) && (lca(w, lca(u, v)) == lca(u, v));
          }
        }
      }
    }

    if (has_path) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
