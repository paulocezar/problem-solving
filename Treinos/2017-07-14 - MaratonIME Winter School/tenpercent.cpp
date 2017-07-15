#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int64_t> L(n);

  for (auto& v : L) cin >> v;
  sort(L.begin(), L.end());

  int m;
  cin >> m;
  while (m--) {
    int64_t q, lo, hi;
    cin >> q;
    lo = (100*q + 109) / 110;
    hi = (100*q) / 90;
    cout << upper_bound(L.begin(), L.end(), hi) - lower_bound(L.begin(), L.end(), lo) << "\n";
  }

  return 0;
}
