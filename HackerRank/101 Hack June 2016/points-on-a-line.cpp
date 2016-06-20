#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<int,int>> pts(n);
  for (auto &pt : pts) cin >> pt.first >> pt.second;

  bool hr = true, vr = true;

  for (int i = 1; i < n; ++i) {
    if (pts[i].first != pts[0].first) hr = false;
  }

  for (int i = 1; i < n; ++i) {
    if (pts[i].second != pts[0].second) vr = false;
  }

  if (hr || vr) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
