#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int ax[1<<17];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<int> Ns(3);
  for (int &n : Ns) {
    cin >> n;
  }

  map<int, int> cnt;
  for (int &n : Ns) {
    for (int i = 0; i < n; ++i) {
      cin >> ax[i];
    }
    int acm = 0;
    for (int i = n-1; i >= 0; --i) {
      acm += ax[i];
      cnt[acm]++;
    }
  }

  int res = 0;
  for (auto &ntry : cnt) {
    if (ntry.second == 3) res = max(res, ntry.first);
  }
  cout << res << "\n";

  return 0;
}
