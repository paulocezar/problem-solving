#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 16;

int low[MAXN], num[MAXN], comp[MAXN], visited[MAXN];

vector<int> gr[MAXN];
vector<int> gg[MAXN];

int cur_num, cur_comp;
stack<int> visiting;

int tarjan_dfs(int u) {
  low[u] = num[u] = cur_num++;
  visiting.push(u);

  visited[u] = 1;
  for (int v : gr[u]) {
    if (visited[v] == 0) low[u] = min(low[u], tarjan_dfs(v));
    else if (visited[v] == 1) low[u] = min(low[u], num[v]);
  }

  if (low[u] == num[u]) {
    int last = -1;
    while (last != u) {
      comp[last = visiting.top()] = cur_comp;
      visited[last] = 2;
      visiting.pop();
    }
    ++cur_comp;
  }

  return low[u];
}

void tarjan_scc(int n) {
  visiting = stack<int>();
  memset(visited, 0, sizeof visited);
  cur_num = cur_comp = 0;

  for (int i = 1; i <= n; ++i)
    if (!visited[i])
      tarjan_dfs(i);
}

int ordered[MAXN], ord;

void doit(int u) {
  ordered[u] = -1;
  for (int v : gg[u]) {
    if (!ordered[v]) doit(v);
  }
  ordered[u] = ord--;
}

int visited_now;
bool check(int u, int t) {
  if (binary_search(gg[u].begin(), gg[u].end(), t)) return true;
  visited[u] = visited_now;
  for (int v : gg[u]) {
    if (visited[v] == visited_now) continue;
    if (check(v, t)) return true;
  }

  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
  }

  vector<pair<int,int>> queries;

  int q;
  cin >> q;
  while (q--) {
    int c, x, y;
    cin >> c >> x >> y;

    if (c == 1) {
      if (y) { y = ++n; swap(x, y); }
      else y = ++n;
      gr[x].push_back(y);
    } else {
      queries.emplace_back(make_pair(x, y));
    }
  }

  tarjan_scc(n);

  for (int u = 1; u <= n; ++u) {
    for (int v : gr[u]) {
      gg[comp[u]].push_back(comp[v]);
    }
  }

  for (int u = 0; u < cur_comp; ++u) {
    sort(gg[u].begin(), gg[u].end());
    gg[u].resize(unique(gg[u].begin(), gg[u].end()) - gg[u].begin());
  }

  ord = cur_comp;
  for (int u = 0; u < cur_comp; ++u) {
    if (!ordered[u]) doit(u);
  }

  visited_now = 13;
  for (auto &query : queries) {
    bool reach = comp[query.first] == comp[query.second];
    if (!reach && (ordered[comp[query.first]] < ordered[comp[query.second]])) {
      visited_now++;
      reach = check(comp[query.first], comp[query.second]);
    }
    cout << (reach ? "Yes\n" : "No\n");
  }

  return 0;
}
