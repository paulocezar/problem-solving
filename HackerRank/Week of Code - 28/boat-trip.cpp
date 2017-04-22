#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, c, m, p, mx = 0;
  cin >> n >> c >> m;

  for (int i = 0; i < n; ++i) {
    cin >> p;
    mx = max(mx, p);
  }

  if (c*m >= mx) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
