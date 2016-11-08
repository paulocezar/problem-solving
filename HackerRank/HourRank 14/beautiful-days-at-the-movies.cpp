#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int rev(int x) {
  int r = 0;
  while (x > 0) {
    r = 10*r + (x % 10);
    x /= 10;
  }
  return r;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int i, j, k;
  cin >> i >> j >> k;
  int res = 0;
  for (int x = i; x <= j; ++x) {
    int d = abs(x - rev(x));
    if (d % k == 0) res++;
  }
  cout << res << "\n";

  return 0;
}
