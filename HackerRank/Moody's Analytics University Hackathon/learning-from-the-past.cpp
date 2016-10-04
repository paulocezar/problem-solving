#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int res = 0;
  vector<int> a(3);
  for (int i = 0; i < n; ++i) {
    for (int &v : a) cin >> v;
    sort(a.begin(), a.end());
    res = max(res, a[1] + a[2]);
  }
  cout << res << "\n";

  return 0;
}
