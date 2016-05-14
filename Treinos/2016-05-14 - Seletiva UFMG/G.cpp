#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1e5 + 1;

int N;

int low[MAXN], lbl[MAXN], dfsnum;
vector<int> gr[MAXN];
bool stkd[MAXN];
int cur_comp, comp[MAXN];
stack< int > scc;

void dfs(int u) {
  lbl[u] = low[u] = dfsnum++;
  scc.push(u);
  stkd[u] = true;

  for (auto &v : gr[u]) {
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

  int M;
  cin >> N >> M;
  while (M--) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
  }

  for (int i = 1; i <= N; ++i) lbl[i] = -1;

  for (int i = 1; i <= N; ++i) if (lbl[i] == -1) dfs(i);

  vector<int> in(cur_comp+1);
  for (int i = 1; i <= N; ++i) {
    for (int &v : gr[i]) {
      if (comp[i] != comp[v]) in[comp[v]]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= cur_comp; ++i) if (!in[i]) ans++;

  cout << max(ans, 1) << "\n";

  return 0;
}
