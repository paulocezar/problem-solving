#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a+n);

  int d1 = a[n-1] - a[0];
  int d2 = a[n-2] - a[0];
  int d3 = a[n-1] - a[1];
  d1 = min(d1, d2);
  d1 = min(d1, d3);

  cout << d1 << "\n";

  return 0;
}
