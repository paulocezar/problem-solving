#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<
  pair<int,int>,
  null_type,
  greater<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>;

const int LGMN = 16;
const int MAXN = 1 << LGMN;

array<vector<int>, MAXN> gr;
array<int, (MAXN << 1)> ID, BL;
array<int, MAXN> L, lo, c, hi, ans;
array<char, MAXN> seen;

struct query {
  int id, l, r, lc, k;
  bool operator < (const query& rhs){
    return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
  }
};

array<query, MAXN> Q;

int P[LGMN][MAXN];

map<int, int> cnt;
ordered_set active;

int cur;
void dfs(int u, int pa = -1) {
  lo[u] = ++cur;
  ID[cur] = u;

  for (int i = 1; i < LGMN; ++i) {
    P[i][u] = P[i - 1][P[i - 1][u]];
  }

  for (int &v : gr[u]) {
    if (v == pa) continue;
    L[v] = L[u] + 1;
    P[0][v] = u;
    dfs(v, u);
  }

  hi[u] = ++cur;
  ID[cur] = u;
}

inline int lca(int u, int v) {
  int log;
  if (L[u] < L[v]) swap(u, v);

  for (log = 1; 1 << log <= L[u]; ++log);
  log--;

  for (int i = log; i >= 0; --i) {
    if (L[u] - (1 << i) >= L[v])
      u = P[i][u];
  }

  if (u == v) return u;

  for (int i = log; i >= 0; --i) {
    if (P[i][u] != P[i][v])
      u = P[i][u], v = P[i][v];
  }

  return P[0][u];
}

inline void add(int x) {
  if (seen[x]) {
    active.erase({cnt[c[x]], c[x]});
    cnt[c[x]]--;
    if (cnt[c[x]]) active.insert({cnt[c[x]], c[x]});
  } else {
    if (cnt[c[x]]) active.erase({cnt[c[x]], c[x]});
    cnt[c[x]]++;
    active.insert({cnt[c[x]], c[x]});
  }
  seen[x] ^= 1;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) cin >> c[i];

  int u, v;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  P[0][1] = 1;
  cur = 0;
  dfs(1);
  int size = sqrt(cur);

  for (int i = 1; i <= cur; ++i) {
    BL[i] = (i - 1) / size + 1;
  }

  for (int i = 0; i < q; ++i) {
    cin >> u >> v >> Q[i].k;
    Q[i].lc = lca(u, v);

    if (lo[u] > lo[v]) swap(u, v);

    if (Q[i].lc == u) {
      Q[i].l = lo[u], Q[i].r = lo[v];
    } else {
      Q[i].l = hi[u], Q[i].r = lo[v];
    }

    Q[i].id = i;
  }

  sort(Q.begin(), Q.begin()+q);

  int curL = Q[0].l, curR = Q[0].l - 1;

  for (int i = 0; i < q; ++i) {
    while (curL < Q[i].l) add(ID[curL++]);
    while (curL > Q[i].l) add(ID[--curL]);
    while (curR < Q[i].r) add(ID[++curR]);
    while (curR > Q[i].r) add(ID[curR--]);

    u = ID[curL], v = ID[curR];

    if (Q[i].lc != u and Q[i].lc != v) add(Q[i].lc);

    ans[Q[i].id] = active.find_by_order(Q[i].k-1)->second;

    if (Q[i].lc != u and Q[i].lc != v) add(Q[i].lc);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
