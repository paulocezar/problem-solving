#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int c[MAXN], pa[MAXN];
int ord[MAXN], sz[MAXN], n, pos;

vector<int> gr[MAXN];
unordered_map<int, int> unq[MAXN];
int totals[MAXN];

void setup(int u) {
  sz[u] = 1;
  for (int v : gr[u]) {
    if (v == pa[u]) continue;
    pa[v] = u;
    setup(v);
    sz[u] += sz[v];
  }
  ord[pos++] = u;
}

int get_centroid(int u) {
  bool is_centroid = true;

  int heaviest_child = 0;

  for (int v : gr[u]) {
    if (v == pa[u]) continue;

    if (2*sz[v] > n) is_centroid = false;
    if (heaviest_child == 0 || sz[v] > sz[heaviest_child]) {
      heaviest_child = v;
    }
  }

  if (is_centroid && 2*(n-sz[u])<=n) {
    return u;
  }

  return get_centroid(heaviest_child);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> n;

  map<int, int> clrs;
  int total_colors = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    if (!clrs.count(c[i])) clrs[c[i]] = ++total_colors;
    c[i] = clrs[c[i]];
    totals[c[i]]++;
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  pos = 0;
  setup(1);

  int root = get_centroid(1);

  pa[root] = root;
  pos = 0;
  setup(root);

  int64 res = 0LL;

  for (int i = 0; i < n; ++i) {
    int u = ord[i];
    sz[u] = 0;

    for (int v : gr[u]) {
      if (v == pa[u]) continue;
      auto &chld = unq[v];
      sz[u] += sz[v];
      if (chld.size() > unq[u].size()) swap(chld, unq[u]);
      for (auto &ntry : chld) {
        bool had = unq[u].count(ntry.first);
        unq[u][ntry.first] += ntry.second;
        if (had && unq[u][ntry.first] == totals[ntry.first]) sz[u]++;
      }
    }

    unq[u][c[u]]++;
    if (unq[u][c[u]] == totals[c[u]]) sz[u]++;

    int64 d1 = unq[u].size();
    int64 d2 = total_colors - sz[u];
    res += d1 * d2;
  }

  cout << res << "\n";


  return 0;
}
