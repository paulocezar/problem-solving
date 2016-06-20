#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1<<17];

inline int biggest(int base, int lim) {
  return base * (lim/base);
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int g;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) g = __gcd(g, a[i]);
    else g = a[i];
  }

  int ans = 0;

  for (int i = 1; i <= (g/i); ++i) {
    if (g % i) continue;
    int bg1 = biggest(i, k);
    int bg2 = biggest(g/i, k);
    if ((bg1 <= k) && (__gcd(g, bg1) > 1)) ans = max(ans, bg1);
    if ((bg2 <= k) && (__gcd(g, bg2) > 1)) ans = max(ans, bg2);
  }

  cout << ans << "\n";

  return 0;
}
