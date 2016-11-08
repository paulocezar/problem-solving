#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int res = 0, prev, cur;
  for (int i = 0; i < n; ++i) {
    cin >> cur;
    if (i) {
      res += (cur != (prev+1)) ?  1 : 0;
    } else {
      res += (cur != 1) ? 1 : 0;
    }
    prev = cur;
  }

  cout << res << "\n";

  return 0;
}
