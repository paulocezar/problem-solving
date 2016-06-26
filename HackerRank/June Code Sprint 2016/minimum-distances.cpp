#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, ax, res = -1;
  map<int, int> prev;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ax;
    if (prev.count(ax)) {
      int dd = i - prev[ax];
      if (res == -1 || dd < res) res = dd;
    }
    prev[ax] = i;
  }

  cout << res << "\n";

  return 0;
}
