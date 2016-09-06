#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 a[1<<12];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a+n);
  k = min(k, n-k);

  int64 best = -1LL;
  for (int beg = 1; beg < n; ++beg) {
    set<int> s;
    for (int i = 0, j = beg; i < k && j < n; ++i, j += 2) {
      s.insert(j);
    }
    if (int(s.size()) < k) break;
    int64 cur = 0LL;
    for (int i = 0; i < n; ++i) {
      if (s.count(i)) {
        for (int j = 0; j < n; ++j) {
          if (s.count(j)) continue;
          cur += abs(a[i]-a[j]);
        }
      }
    }
    if (best == -1LL || cur < best) best = cur;
  }

  cout << best << "\n";

  return 0;
}
