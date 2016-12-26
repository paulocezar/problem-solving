#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXV = 1 << 17;
const double PHI = 0.5 * (1.0 + sqrt(5.0));
const double EPS = 1e-9;

int a[32];

int lwr[MAXV], upr[MAXV];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    int n;
    cin >> n;

    int xr = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      xr ^= a[i];
    }

    if (n & 1) {
      cout << (xr ? "Sherlock" : "Watson") << "\n";
    } else {
      if (a[0] > a[1]) swap(a[0], a[1]);
      cout << ((a[0] - int((a[1]-a[0])*PHI + EPS)) ? "Sherlock" : "Watson") << "\n";
    }
  }

  return 0;
}
