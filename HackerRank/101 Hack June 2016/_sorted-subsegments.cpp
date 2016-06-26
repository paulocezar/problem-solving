#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1<<17], from, to;

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int n, q, k;
  cin >> n >> q >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  while (q--) {
    cin >> from >> to;
    sort(a+from, a+to+1);
  }

  cout << a[k] << "\n";

  return 0;
}
