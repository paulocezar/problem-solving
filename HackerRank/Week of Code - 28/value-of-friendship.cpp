#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int pa[MAXN], rk[MAXN], sz[MAXN];

int find(int x) {
    int px = x, ax;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rk[y] > rk[x]) swap(x,y);
    if (rk[x] == rk[y]) rk[x]++;
    pa[y] = x;
    sz[x] += sz[y];
    return true;
}

int64 sum(int64 n) {
  return (n*n*n - n) / 3LL;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
      pa[i] = i;
      rk[i] = 0;
      sz[i] = 1;
    }

    int64 total = 0LL;
    int tree_edges = 0;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      if (fUnion(u, v)) {
        tree_edges++;
      }
    }

    int64 extra = 0LL;
    vector<int> comp;

    for (int i = 1; i <= n; ++i) {
      if (pa[i] == i) {
        comp.push_back(sz[i]);
        total += sum(sz[i]);
        extra += int64(sz[i]) * int64(sz[i]-1LL);
      }
    }
    int64 rem = m - tree_edges;
    total += rem * extra;

    sort(comp.begin(), comp.end(), greater<int>());
    for (int s : comp) {
      tree_edges -= s - 1;
      int64 w = int64(s) * int64(s - 1);
      total += int64(tree_edges) * w;
    }

    cout << total << "\n";
  }

  return 0;
}
