#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int64 tt, ww, ti, wi;
  cin >> tt >> ww;

  priority_queue<int64> best;
  vector<pair<int64, int64>> worst;

  for (int i = 1; i < n; ++i) {
    cin >> ti >> wi;
    if (ti > tt) {
      int64 need = wi - ti + 1LL;
      best.push(-need);
    } else {
      worst.push_back({-ti,wi});
    }
  }

  sort(worst.begin(), worst.end());
  int fw = 0, wsz = worst.size();

  int res = best.size();

  while (!best.empty()) {
    int64 need = -best.top();
    if (need > tt) break;
    best.pop();
    tt -= need;
    while (fw < wsz) {
      if (tt >= -worst[fw].first) break;
      need = worst[fw].second + worst[fw].first + 1LL;
      best.push(-need);
      fw++;
    }

    res = min(res, int(best.size()));
  }

  cout << res + 1 << "\n";

  return 0;
}
