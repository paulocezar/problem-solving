#include <bits/stdc++.h>

using namespace std;

const int MAXN = 64;

inline int negated(int var) { return var ^ 1; }

namespace TwoSAT {
  array<int, MAXN> low, lbl, belongs_to;
  array<bool, MAXN> is_stacked;
  array<vector<int>, MAXN> gr;
  int dfsnum, components, n;

  stack<int> scc;

  void init(int sz) {
    n = sz;
    for (int i = 0; i < n; ++i) gr[i].clear();
    fill(lbl.begin(), lbl.begin() + n, -1);
    components = 0;
  }

  void dfs(int u) {
    lbl[u] = low[u] = dfsnum++;

    scc.push(u);
    is_stacked[u] = true;

    for (int v : gr[u]) {
      if (lbl[v] == -1) dfs(v);
      if (is_stacked[v]) low[u] = min(low[u], low[v]);
    }

    auto pop = [&]() {
      belongs_to[scc.top()] = components;
      is_stacked[scc.top()] = false;
      scc.pop();
    };

    if (low[u] == lbl[u]) {
      while (!scc.empty() && scc.top() != u) {
        pop();
      }
      pop();
      components++;
    }
  }

  void add_or_clause(int x, int y) {
    gr[negated(x)].push_back(y);
    gr[negated(y)].push_back(x);
  }

  bool is_solvable() {
    for (int i = 0; i < n; ++i)
      if (lbl[i] == -1) dfs(i);

    for (int i = 0; i < n; i += 2) {
      if (belongs_to[i] == belongs_to[i + 1]) return false;
    }

    return true;
  }

  // is_true assumes that is_solvable was already called and returned true
  bool is_true(int var) {
    // tarjan already produces SCC in reverse topological order of the SCC graph
    // to know if a variable is true we just need to check if the SCC it is in
    // appears earlier than the SCC where its negation is
    return belongs_to[var] < belongs_to[negated(var)];
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m && (n || m)) {
    int couple1, couple2, var1, var2;
    char partner1, partner2;

    TwoSAT::init(2 * n);

    while (m--) {
      cin >> couple1 >> partner1 >> couple2 >> partner2;
      var1 = (couple1 << 1) ^ (partner1 == 'h' ? 1 : 0);
      var2 = (couple2 << 1) ^ (partner2 == 'h' ? 1 : 0);
      TwoSAT::add_or_clause(var1, var2);
    }

    // the bride must seat on the same side as the bride :)
    TwoSAT::add_or_clause(0, 0);

    if (TwoSAT::is_solvable()) {
      for (int i = 1; i < n; ++i) {
        cout << i << (TwoSAT::is_true(2*i) ? "w" : "h") << " \n"[i+1==n];
      }
    } else cout << "bad luck\n";
  }

  return 0;
}
