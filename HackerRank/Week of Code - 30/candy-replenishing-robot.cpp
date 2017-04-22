#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, t;
  cin >> n >> t;

  int cur = n, res = 0;

  for (int i = t-1; i >= 0; --i) {
    int c; cin >> c;
    cur -= c;
    if (i && cur < 5) {
      res += n - cur;
      cur = n;
    }
  }

  cout << res << "\n";

  return 0;
}
