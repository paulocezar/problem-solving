#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, p;
  cin >> n >> p;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = (a[i] + p - 1) / p;
  }

  sort(a, a+n);

  int64 res = a[0];

  for (int i = 1; i < n; ++i) {
    if (a[i] <= a[i-1]) {
      a[i] = a[i-1] + 1;
    }
    res += a[i];
  }

  cout << res << "\n";

  return 0;
}
