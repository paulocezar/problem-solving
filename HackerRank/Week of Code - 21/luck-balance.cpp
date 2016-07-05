#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int ans = 0;
  vector<int> imp;

  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    int ax, clazz;
    cin >> ax >> clazz;
    if (clazz) {
      imp.push_back(ax);
    } else {
      ans += ax;
    }
  }

  sort(imp.begin(), imp.end());
  reverse(imp.begin(), imp.end());

  for (auto &v : imp) {
    if (K) { ans += v; K--; }
    else { ans -= v; }
  }

  cout << ans << "\n";

  return 0;
}
