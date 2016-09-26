#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

vector<int> gr[MAXN];
int64 c[MAXN];
int64 val[MAXN];

int64 bad_c, incr;

void doit(int u, int pa = -1) {
  val[u] += incr;
  for (int v : gr[u]) {
    if (v == pa || c[v] == bad_c) continue;
    doit(v, u);
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> c[i];

  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int64 lastAns = 0LL, u;
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    if (n == 1) {
      cin >> u >> bad_c >> incr;
      u ^= lastAns;
      bad_c ^= lastAns;
      incr ^= lastAns;
      if (c[u] != bad_c) doit(u);
    } else {
      cin >> u;
      u ^= lastAns;
      lastAns = val[u];
      cout << lastAns << "\n";
    }
  }

  return 0;
}
