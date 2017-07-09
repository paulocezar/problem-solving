#include <bits/stdc++.h>

using namespace std;

const int MAXSZ = 1 << 17;
const int MAXM = 1000;

int pa[MAXSZ], rk[MAXSZ];

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

int s[MAXM];
int cache[MAXM][MAXM];
char cached[MAXM][MAXM];

int doit(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;

  int& ret = cache[l][r];
  if (cached[l][r]) return ret;
  cached[l][r] = 1;
  ret = doit(l+1, r);
  ret = max(ret, doit(l, r-1));
  if (find(s[l]) == find(s[r])) ret = max(ret, 2 + doit(l+1, r-1));
  return ret;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k, m;
  cin >> n >> k >> m;

  for (int i = 1; i <= n; ++i) {
    pa[i] = i;
    rk[i] = 0;
  }

  for (int i = 0; i < k; ++i) {
    int u, v; cin >> u >> v;
    fUnion(u, v);
  }

  for (int i = 0; i < m; ++i) cin >> s[i];

  cout << doit(0, m-1) << "\n";

  return 0;
}
