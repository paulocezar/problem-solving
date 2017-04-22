#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class edge_t {
public:
  int u, v, a, b;
};

const int MAXN = 1 << 17;
edge_t edges[MAXN];

class disjoint_set {
public:
  disjoint_set(int n) {
    pa.resize(n); rk.resize(n);
    for (int i = 0; i < n; ++i) pa[i] = i, rk[i] = 0;
  }

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

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rk[y] > rk[x]) swap(x, y);
    if (rk[x] == rk[y]) rk[x]++;
    pa[y] = x;
    return true;
  }

private:
  vector<int> pa, rk;
};

int64 gcd(int64 a, int64 b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].a >> edges[i].b;
  }

  auto doit = [&] () -> pair<int64,int64> {
    int64 A = 0LL, B = 0LL;
    disjoint_set ds(n);

    for (int i = 0; i < m; ++i) {
      if (ds.join(edges[i].u, edges[i].v)) {
        A += edges[i].a;
        B += edges[i].b;
      }
    }

    int64 g = gcd(A, B);
    A /= g; B /= g;
    return {A, B};
  };

  sort(edges, edges+m, [](const edge_t &e1, const edge_t &e2) {
    if (e1.a != e2.a) return e1.a > e2.a;
    return e1.b < e2.b;
  });
  auto r1 = doit();

  sort(edges, edges+m, [](const edge_t &e1, const edge_t &e2) {
    if (e1.b != e2.b) return e1.b < e2.b;
    return e1.a > e2.a;
  });
  auto r2 = doit();

  if (r2.first * r1.second > r1.first * r2.second) {
    r1 = r2;
  }

  sort(edges, edges+m, [](const edge_t &e1, const edge_t &e2) {
    int d1 = e1.a - e1.b;
    int d2 = e2.a - e2.b;
    if (d1 != d2) return d1 < d2;
    if (e1.b != e2.b) return e1.b < e2.b;
    return e1.a > e2.a;
  });
  r2 = doit();

  if (r2.first * r1.second > r1.first * r2.second) {
    r1 = r2;
  }

  cout << r1.first << "/" << r1.second << "\n";

  return 0;
}
