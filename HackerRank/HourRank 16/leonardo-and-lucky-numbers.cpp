#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int64 n;
    cin >> n;
    int64 x = 0;
    bool ok = false;
    while (7LL*x <= n) {
      if (((n-7LL*x) % 4LL) == 0) {
        ok = true;
        break;
      }
      x++;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
