#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

char seen[MAXN];
vector<int> gr[MAXN];


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {

    int n, m, clib, croad;
    cin >> n >> m >> clib >> croad;
    croad = min(croad, clib);

    int64 res = 0LL;

    for (int i = 1; i <= n; ++i) {
      gr[i].clear();
      seen[i] = 0;
    }

    while (m--) {
      int u, v; cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
      if (!seen[i]) {
        res += clib;
        queue<int> q;
        q.push(i); seen[i] = 1;
        while (!q.empty()) {
          int u = q.front(); q.pop();
          for (int &v : gr[u]) if (!seen[v]) {
            seen[v] = 1;
            res += croad;
            q.push(v);
          }
        }
      }
    }

    cout << res << "\n";
  }

  return 0;
}
