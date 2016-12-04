#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int LGMN = 18;
const int MAXN = 1 << LGMN;
const int MAXQ = 1 << 17;

vector< int > gr[MAXN];
vector< int > qr[MAXN];
int res[MAXQ];

int L[MAXN], T[MAXN];
int P[MAXN][LGMN];

int N;

void dfs(int u) {
  for (int &v : gr[u]) {
    if (!T[v]) {
      T[v] = u;
      L[v] = L[u] + 1;
      dfs(v);
    }
  }
}

void process() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; (1 << j) < N; ++j){
      P[i][j] = -1;
    }
  }

  for (int i = 1; i <= N; ++i) {
    P[i][0] = T[i];
  }

  for (int j = 1; (1 << j) < N; ++j) {
    for (int i = 1; i <= N; ++i) {
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }
}

int lca(int u, int v) {
  int log;

  if (L[u] < L[v]) swap(u, v);

  for (log = 1; 1 << log <= L[u]; ++log);
  log--;

  for (int i = log; i >= 0; --i){
    if (L[u] - (1 << i) >= L[v])
      u = P[u][i];
  }

  if (u == v) return u;

  for (int i = log; i >= 0; --i) {
    if (P[u][i] != -1 && P[u][i] != P[v][i])
      u = P[u][i], v = P[v][i];
  }

  return T[u];
}

int dist(int u, int v) {
  return L[u] + L[v] - 2 * L[lca(u, v)];
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> N >> q;

  for (int i = 1; i < N; ++i) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  T[1] = 1;
  dfs(1);
  T[1] = -1;
  process();

  for (int qq = 0; qq < q; ++qq) {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
      int v; cin >> v;
      qr[v].push_back(qq);
    }
  }

  for (int u = 1; u <= N; ++u) {
    for (int v = u+1; v <= N; ++v) {
      int cur = ((int64(u) * int64(v)%MOD) * int64(dist(u, v))) % MOD;

      int j = 0, k = 0;
      while (j < qr[u].size()  && k < qr[v].size()) {
        if (qr[u][j] == qr[v][k]) {
          res[qr[u][j]] += cur;
          if (res[qr[u][j]] >= MOD) res[qr[u][j]] -= MOD;
          j++, k++;
        } else if (qr[u][j] < qr[v][k]) {
          j++;
        } else {
          k++;
        }
      }
    }
  }

  for (int qq = 0; qq < q; ++qq) {
    cout << res[qq] << "\n";
  }

  return 0;
}
