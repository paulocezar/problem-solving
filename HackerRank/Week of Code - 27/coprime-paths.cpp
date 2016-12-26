#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int SQMP = 57;
const int MAXP = 3163;

const int LGMN = 15;
const int MAXN = 1 << LGMN;

const int MAXVAL = 1 << 24;

int L[MAXN], P[LGMN][MAXN];
int lo[MAXN], hi[MAXN], ID[MAXN << 1], BL[MAXN << 1];

char seen[MAXN];

int inc[8];

int cnt[MAXVAL];
int ans[MAXN];

int node[MAXN][8];

vector<int> gr[MAXN];

bitset< MAXP+1 > bs;
vector<int> primes;

struct query {
  int id, l, r, lc, nds;
  bool operator < (const query& rhs){
    return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
  }
} Q[MAXN];


void sieve() {
  for (int i = 1; i <= MAXP; ++i) {
    bs[i] = i & 1;
  }
  bs[1] = 0; bs[2] = 1;
  for (int i = 3; i <= SQMP; i += 2) if (bs[i]) {
    for (int j = i*i; j <= MAXP; j += i) {
      bs[j] = 0;
    }
  }
  primes.clear(); primes.push_back(2);
  for (int i = 3; i <= MAXP; i += 2) if (bs[i]) {
    primes.push_back(i);
  }
}

int cur;
void dfs(int u, int pa) {
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

inline void add(int x, int &res) {
  if (seen[x]) {
    int ncp = 0;
    for (int i = 1; i <= node[x][0]; ++i) {
      cnt[node[x][i]]--;
      if (inc[i]) ncp += cnt[node[x][i]];
      else ncp -= cnt[node[x][i]];
    }
    res -= ncp;
  } else {
    int ncp = 0;
    for (int i = 1; i <= node[x][0]; ++i) {
      if (inc[i]) ncp += cnt[node[x][i]];
      else ncp -= cnt[node[x][i]];
      cnt[node[x][i]]++;
    }
    res += ncp;
  }
  seen[x] ^= 1;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  sieve();
  for (int i = 0; i < 8; ++i) inc[i] = __builtin_popcount(i) & 1;

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    int v; cin >> v;
    vector<int> fac;
    for (int &p : primes) {
      if (p*p > v) break;
      if (v % p) continue;
      while ((v % p) == 0) v /= p;
      fac.push_back(p);
    }
    if (v != 1) fac.push_back(v);
    int pf = fac.size();
    node[i][0] = (1 << pf) - 1;
    for (int j = 1; j <= node[i][0]; ++j) {
      node[i][j] = 1;
      for (int k = 0; k < pf; ++k) if (j & (1<<k)) {
        node[i][j] *= fac[k];
      }
    }
  }

  int u, v;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  P[0][1] = 1;
  cur = 0;
  dfs(1, -1);
  int size = sqrt(cur);

  for (int i = 1; i <= cur; ++i) {
    BL[i] = (i - 1) / size + 1;
  }

  for (int i = 0; i < q; ++i) {
    cin >> u >> v;
    Q[i].lc = lca(u, v);
    Q[i].nds = L[u] + L[v] - 2 * L[Q[i].lc] + 1;

    if (lo[u] > lo[v]) swap(u, v);

    if (Q[i].lc == u) {
      Q[i].l = lo[u], Q[i].r = lo[v];
    } else {
      Q[i].l = hi[u], Q[i].r = lo[v];
    }

    Q[i].id = i;
  }

  sort(Q, Q+q);

  int curL = Q[0].l, curR = Q[0].l - 1, res = 0;

  for (int i = 0; i < q; ++i) {

    while (curL < Q[i].l) add(ID[curL++], res);
    while (curL > Q[i].l) add(ID[--curL], res);
    while (curR < Q[i].r) add(ID[++curR], res);
    while (curR > Q[i].r) add(ID[curR--], res);

    u = ID[curL], v = ID[curR];

    if (Q[i].lc != u and Q[i].lc != v) add(Q[i].lc, res);

    int all = (Q[i].nds * (Q[i].nds - 1)) / 2;
    ans[Q[i].id] = all - res;

    if (Q[i].lc != u and Q[i].lc != v) add(Q[i].lc, res);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
