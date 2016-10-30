#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXF = 1 << 14;
const int MAXQ = 1 << 17;

vector<int> restaurants[MAXF];

int lca(int u, int v) {
  int res = 0;
  while (u != v) {
    res++;
    if (u > v) {
      u /= 2;
    } else {
      v /= 2;
    }
  }
  return res;
}
int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  for (int f = 1; f <= m; ++f) {
    int ax; cin >> ax;
    while (ax--) {
      int r; cin >> r;
      restaurants[f].push_back(r);
    }
  }

  int res = 0;

  int was_at = 1;
  for (int i = 0; i < q; ++i) {
    int food, person;
    cin >> food >> person;

    int ax = n + 1;
    for (int r : restaurants[food]) {
      ax = min(ax, lca(was_at, r) + lca(r, person));
    }
    res += ax;

    was_at = person;
  }


  cout << res << "\n";

  return 0;
}
