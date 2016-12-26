#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    int n; cin >> n;
    int p, xr = 0;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      if (p & 1) {
        p++;
      } else {
        p--;
      }
      xr ^= p;
    }
    cout << (xr ? "W" : "L") << "\n";
  }

  return 0;
}
