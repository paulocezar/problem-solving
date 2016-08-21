#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

int low[MAXN], lbl[MAXN], dfsnum;
vector<int> gr[MAXN];
bool stkd[MAXN], has_parent[MAXN];
int cur_comp, comp[MAXN];
stack< int > scc;

void dfs(int u) {
  lbl[u] = low[u] = dfsnum++;
  scc.push(u);
  stkd[u] = true;

  for (int i = 0, sz = gr[u].size(); i < sz; ++i) {
    int v = gr[u][i];
    if (lbl[v] == -1) dfs(v);
    if (stkd[v]) low[u] = min(low[u], low[v]);
  }

  if (low[u] == lbl[u]) {
    cur_comp++;
    while (!scc.empty() && scc.top() != u) {
      comp[scc.top()] = cur_comp;
      stkd[scc.top()] = false;
      scc.pop();
    }
    scc.pop(); stkd[u] = false;
    comp[u] = cur_comp;
  }
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
      lbl[i] = -1;
      has_parent[i] = false;
      gr[i].clear();
    }

    while (M--) {
      int u, v;
      cin >> u >> v;
      gr[u].push_back(v);
    }

    cur_comp = 0;
    for (int i = 1; i <= N; ++i) if (lbl[i] == -1) {
      dfs(i);
    }

    for (int i = 1; i <= N; ++i) {
      for (int j = 0, sz = gr[i].size(); j < sz; ++j) {
        if (comp[i] != comp[gr[i][j]]) {
          has_parent[comp[gr[i][j]]] = true;
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= cur_comp; ++i) if (!has_parent[i]) {
      ans++;
    }

    cout << max(ans, 1) << "\n";
  }

  return 0;
}
