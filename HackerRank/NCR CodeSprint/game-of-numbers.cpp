#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  vector<string> p = {"Alice", "Bob"};

  int g;
  cin >> g;
  while (g--) {
    int l, r, k;
    cin >> l >> r >> k;
    int win = 0;
    if (k > r) {
      int x  = k % (l + r);
      win = ((x == 0) || (x > r)) ? 1 : 0;
    }
    cout << p[win] << "\n";
  }

  return 0;
}
