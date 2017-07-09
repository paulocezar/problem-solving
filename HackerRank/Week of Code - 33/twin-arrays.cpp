#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  using el = pair<int,int>;

  auto improve = [](pair<el,el>& a, const el& b) {
    if (b.first <= a.first.first) {
      swap(a.first, a.second);
      a.first = b;
    } else if (b.first < a.second.first) {
      a.second = b;
    }
  };

  pair<el, el> a = {{1e9, 0}, {1e9, 0}};
  for (int i = 0; i < n; ++i) {
    int ai; cin >> ai;
    improve(a, {ai, i});
  }

  pair<el, el> b = {{1e9, 0}, {1e9, 0}};
  for (int i = 0; i < n; ++i) {
    int bi; cin >> bi;
    improve(b, {bi, i});
  }

  int res = 0;
  if (a.first.second != b.first.second) {
    res = a.first.first + b.first.first;
  } else {
    res = min(a.first.first+b.second.first, a.second.first+b.first.first);
  }
  cout << res << "\n";

  return 0;
}
