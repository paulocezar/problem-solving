#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1<<14];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; ++i) cin >> a[i];

  unordered_set<int> has;
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (has.count(a[i]+d) && has.count(a[i]+(d<<1))) ans++;
    has.insert(a[i]);
  }
  cout << ans << "\n";

  return 0;
}
