#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[16];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
      cin >> a[i];
  }

  int gg = 0;
  for (int j = 0; j < m; ++j) {
      int bi; cin >> bi;
      gg = __gcd(gg, bi);
  }

  int mm = 1;
  for (int i = 0; i < n; ++i) {
      mm = (mm / __gcd(mm, a[i])) * a[i];
      if (mm > gg) break;
  }

  int res = 0;
  for (int i = 1; i*i <= gg; ++i) {
      if (gg % i) continue;
      if ((i % mm) == 0) res++;
      if (((i*i) != gg) && (((gg/i)%mm) == 0)) res++;
  }
  cout << res << "\n";

  return 0;
}
