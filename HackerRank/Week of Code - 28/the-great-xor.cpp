#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int64 x;
    cin >> x;
    int64 res = 0LL;
    for (int64 a = 1LL; a < x; a <<= 1) {
      if (a & x) continue;
      res += a;
    }
    cout << res << "\n";
  }

  return 0;
}
