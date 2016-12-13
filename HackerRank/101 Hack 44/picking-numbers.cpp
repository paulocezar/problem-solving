#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cnt[128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    cnt[x]++;
  }

  int res = 2;
  for (int i = 1; i < 100; ++i) {
    res = max(res, cnt[i] + cnt[i+1]);
  }

  cout << res << "\n";

  return 0;
}
