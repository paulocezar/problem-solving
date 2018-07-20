#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

array<int, MAXN + 1> pa, rk;

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
  if (rk[y] > rk[x]) swap(x, y);
  if (rk[x] == rk[y]) rk[x]++;
  pa[y] = x;
  return true;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, C, u, v, c;
  cin >> N >> C;

  using edge = tuple<int,int,int>;
  vector<edge> edges; edges.reserve(C);
  while (C--) {
    cin >> u >> v >> c;
    edges.emplace_back(c,u,v);
  }

  sort(edges.begin(), edges.end());
  for (int i = 0; i <= N; ++i) pa[i] = i, rk[i] = 0;

  int res = 0;
  for (auto& e : edges) {
    tie(c, u, v) = e;
    if (fUnion(u, v)) res += c;
  }
  cout << res << "\n";

  return 0;
}
