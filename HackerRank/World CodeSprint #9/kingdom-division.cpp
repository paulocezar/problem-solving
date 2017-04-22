#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 17;

vector<int> gr[MAXN];

int cache[2][2][MAXN];
char cached[2][2][MAXN];

int solve(int u, int c, int has, int pa = -1) {
  int &res = cache[c][has][u];
  if (cached[c][has][u]) return res;
  cached[c][has][u] = 1;

  int64 all = 1LL;
  int64 bad = 1LL;
  for (int v : gr[u]) {
    if (v == pa) continue;

    int ok = solve(v, c, 1, u);
    int maybenot = solve(v, 1-c, 0, u);

    all *= (ok + maybenot); all %= MOD;
    bad *= maybenot; bad %= MOD;
  }

  if (has) res = all;
  else res = (all - bad + MOD) % MOD;

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int res = solve(1, 0, 0) + solve(1, 1, 0);
  if (res >= MOD) res -= MOD;
  cout << res << "\n";

  return 0;
}
