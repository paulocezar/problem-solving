#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int LGMN = 17;
const int MAXN = 1 << LGMN;

int parent[MAXN];
int pomekon[MAXN];
int L[MAXN];

int P[LGMN][MAXN];
int best[LGMN][MAXN];

vector<pair<int,int>> gr[MAXN];

int N;

void process() {
  int i, j;

  for (i = 0; (1<<i) < N; ++i) {
    for (j = 0; j < N; ++j) {
      P[i][j] = -1;
    }
  }

  for (i = 0; i < N; ++i) {
    P[0][i] = parent[i];
    best[0][i] = pomekon[i];
  }

  for (i = 1; (1 << i) < N; ++i) {
    for (j = 0; j < N; ++j) {
      if (P[i-1][j] != -1) {
        P[i][j] = P[i-1][P[i-1][j]];
        best[i][j] = max(best[i-1][j], best[i-1][P[i-1][j]]);
      }
    }
  }
}

pair<int,int> query(int p, int q) {
  int log, i;

  if (L[p] < L[q]) {
    swap(p, q);
  }

  for (log = 1; (1 << log) <= L[p]; log++);
  log--;

  int res = 0;
  for (i = log; i >= 0; --i) {
    if ((L[p] - (1 << i)) >= L[q]) {
      res = max(res, best[i][p]);
      p = P[i][p];
    }
  }

  if (p == q) {
    return {p, res};
  }

  for (i = log; i >= 0; --i) {
    if ((P[i][p] != -1) && (P[i][p] != P[i][q])) {
      res = max(res, max(best[i][p], best[i][q]));
      p = P[i][p], q = P[i][q];
    }
  }

  res = max(res, max(pomekon[p], pomekon[q]));
  return {parent[p], res};
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int K;
  cin >> N >> K;

  for (int i = 1; i < N; ++i) {
    parent[i] = -1;
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    gr[u].emplace_back(v, c);
    gr[v].emplace_back(u, c);
  }

  queue<int> q;
  q.push(0);
  parent[0] = 0;
  L[0] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto &w : gr[u]) {
      if (parent[w.first] != -1) continue;
      pomekon[w.first] = w.second;
      parent[w.first] = u;
      L[w.first] = L[u] + 1;
      q.push(w.first);
    }
  }
  pomekon[0] = 0;
  parent[0] = -1;

  process();

  int dp[K+1];
  for (int i = 0; i <= K; ++i) dp[i] = 0;

  int Q;
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    auto ans = query(u, v);
    int w = L[u] + L[v] - (2 * L[ans.first]) + 1;
    int c = ans.second;
    for (int kk = K; kk >= w; --kk) dp[kk] = max(dp[kk], dp[kk-w] + c);
  }
  if (dp[K] == 0) dp[K] = -1;

  cout << dp[K] << "\n";

  return 0;
}
