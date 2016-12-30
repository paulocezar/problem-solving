#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 32;

int t[MAXN], n;

set<pair<int,int>> solve(int at = 0, int xx = 0, int yy = 0) {
  set<pair<int,int>> res;
  if (at == n) return res;

  int dx, dy;
  if (at & 1) {
    dx = 1, dy = 1;
  } else {
    dx = 0, dy = 1;
  }
  res = solve(at + 1, xx + t[at]*dx, yy + t[at]*dy);

  for (int i = 1; i <= t[at]; ++i) {
    res.insert(make_pair(xx + i*dx, yy + i*dy));
  }

  set<pair<int,int>> nxt;
  if (at & 1) {
    for (auto &v  : res) {
      nxt.insert(make_pair(xx-(v.second-yy), yy+(v.first-xx)));
    }
  } else if (at) {
    for (auto &v  : res) {
      nxt.insert(make_pair(xx+(v.second-yy), yy-(v.first-xx)));
    }
  }

  res.insert(nxt.begin(), nxt.end());
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  auto res = solve();
  cout << res.size() << "\n";

  return 0;
}
