#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  auto digsum = [](int x) -> int {
    int r = 0;
    while (x) {
      r += x % 10;
      x /= 10;
    }
    return r;
  };

  int res = 1;
  for (int i = 1; i*i <= n; ++i) {
    if (n % i) continue;
    for (int v : {i, n/i}) {
      if (digsum(v) > digsum(res)) res = v;
      else if (digsum(v) == digsum(res) && v < res) res = v;
    }
  }
  cout << res << "\n";

  return 0;
}
