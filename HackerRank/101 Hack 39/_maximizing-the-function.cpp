#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1<<17];

int doit(int lo, int hi) {
  int res = 0;
  for (int i = lo; i <= hi; ++i) {
    int cnt = 0;
    for (int j = i; j <= hi; ++j) {
      cnt ^= a[j];
      res += cnt;
    }
  }
  return res;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    while (q--) {
      int x, y, k;
      cin >> x >> y >> k;
      int res = doit(x, y);
      if (k) {
        for (int ax = x; ax <= y; ++ax) {
          a[ax] = 1 - a[ax];
          res = max(res, doit(x, y));
          a[ax] = 1 - a[ax];
        }
      }
      cout << res << "\n";
    }

    return 0;
}
