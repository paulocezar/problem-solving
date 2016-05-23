#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k && (n % (k<<1))) {
      cout << "-1\n";
    } else {
      int x = k;
      for (int i = 1; i <= n; ++i) {
        cout << (i + x) << " ";
        if (k && (i % k == 0)) x = -x;
      }
      cout << "\n";
    }
  }


  return 0;
}
