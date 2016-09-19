#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int LOGN = 17;
const int MAXN = 1 << LOGN;


int64 rooted_sqsum[MAXN];
int64 rooted_sum[MAXN];
int rooted_nodes[MAXN];

vector<int> gr[MAXN];

int T[MAXN], L[MAXN];
int P[MAXN][LOGN];
int64 PS[MAXN][LOGN];
int64 PNS[MAXN][LOGN];
int64 PN[MAXN][LOGN];

int64 increase_dists(int root, int64 by) {
  return rooted_sqsum[root] + 2LL * by * rooted_sum[root] + rooted_nodes[root] * by * by;
}

void process(int u) {
  rooted_nodes[u] = 1;

  for (int v : gr[u]) {
    L[v] = L[u] + 1;
    process(v);
    rooted_nodes[u] += rooted_nodes[v];
    rooted_sum[u] += rooted_sum[v] + rooted_nodes[v];
    rooted_sqsum[u] += increase_dists(v, 1LL);
  }
}

pair<int, int64> lca(int p, int q) {
    if (L[p] < L[q]) {
      swap(p, q);
    }

    int log = 1;
    while ((1<<log) <= L[p]) ++log;
    log--;

    int64 path_sum = 0LL;
    int64 path_nodes = 0LL;
    int add = 0;
    for (int i = log; i >= 0; --i) {
      if (L[p] - (1 << i) >= L[q]) {
        path_sum += PS[p][i];
        path_nodes += PNS[p][i] + add * PN[p][i];
        add += (1<<i);
        p = P[p][i];
      }
    }

    if (p != q) {
      for (int i = log; i >= 0; --i) {
        if (P[p][i] && P[p][i] != P[q][i]) {
          path_sum += PS[p][i];
          path_nodes += PNS[p][i] + add * PN[p][i];
          add += (1<<i);
          p = P[p][i], q = P[q][i];
        }
      }

      path_sum += PS[p][0];
      path_nodes += PNS[p][0] + add * PN[p][0];
      p = T[p];
    }
    return {p, path_sum + path_nodes};
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    cin >> T[i];
    gr[T[i]].push_back(i);
  }

  process(1);

  for (int i = 1; i <= n; ++i) {
    P[i][0] = T[i];
    PS[i][0] = rooted_sum[i];
    PN[i][0] = rooted_nodes[i];
    PNS[i][0] = rooted_nodes[i];
  }

  for (int j = 1; (1 << j) < n; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (P[i][j - 1]) {
        PS[i][j] = PS[i][j - 1] + PS[P[i][j - 1]][j - 1];
        PN[i][j] = PN[i][j - 1] + PN[P[i][j - 1]][j - 1];
        PNS[i][j] = PNS[i][j - 1] + PNS[P[i][j - 1]][j - 1] + int64(1 << (j - 1)) * PN[P[i][j - 1]][j - 1];
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }

  int q, u, v, l;
  int64 res, discard;
  cin >> q;
  while (q--) {
    cin >> u >> v;
    if (u == v) {
      res = rooted_sqsum[u];
    } else {
      tie(l, discard) = lca(u, v);
      if (l == v) {
        res = increase_dists(v, L[u] - L[v]) - 4LL * discard;
      } else {
        res = increase_dists(v, L[u] + L[v] - 2 * L[l]);
      }
    }
    cout << res << "\n";
  }

  return 0;
}
