#include <bits/stdc++.h>

using namespace std;

struct edge_t {
  int u, v, w;
  edge_t(int a = 0, int b = 0, int c = 0) : u{a}, v{b}, w{c} {}
  bool operator <(const edge_t& e) const {
    return w < e.w;
  }
};

const int MAXN = 1 << 17;
array<int, MAXN> pa, rk;

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
  return true;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<edge_t> edges(m);

  for (auto& e : edges) cin >> e.u >> e.v >> e.w;
  sort(edges.begin(), edges.end());

  for (int i = 1; i <= n; ++i) pa[i] = i, rk[i] = 0;

  int64_t res = 0;
  int needed = n-2;
  int low = 0;
  for (auto& e : edges) {
    if (find(e.u) != find(e.v)) {
      if (needed > 0) {
        needed--;
        res += e.w;
        fUnion(e.u, e.v);
      } else {
        low = e.w;
        break;
      }
    }
  }

  for (int i = 1; i <= n; ++i) pa[i] = i, rk[i] = 0;
  int ways = 0;
  for (auto& e : edges) {
    if (e.w >= low) {
      if (find(e.u) != find(e.v)) ways++;
    } else {
      fUnion(e.u, e.v);
    }
  }


  cout << res << " " << ways << "\n";

  return 0;
}
