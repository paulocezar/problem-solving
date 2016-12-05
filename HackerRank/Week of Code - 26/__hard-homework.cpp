#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  bool f = true;
  double res;

  for (int x = 1; x <= n; ++x) {
    for (int y = x; y <= n; ++y) {
      int z = n - x - y;
      if (z < y) break;
      double cur = sin(x) + sin(y) + sin(z);
      if (f) res = cur, f = false;
      res = max(res, cur);
    }
  }

  cout << fixed << setprecision(9) << res << "\n";

  return 0;
}
