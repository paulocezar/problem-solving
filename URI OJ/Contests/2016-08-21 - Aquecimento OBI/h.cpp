#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

vector<pair<int,double>> elves(MAXN);

double acm[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, D;
  cin >> N >> D;
  elves.resize(N);
  for (auto &e : elves) cin >> e.first;

  for (auto &e : elves) cin >> e.second;

  sort(elves.begin(), elves.end());

  acm[0] = elves[0].second;
  for (int i = 1; i < N; ++i) {
    acm[i] = acm[i-1] + elves[i].second;
  }

  int last_end = -1;
  int groups = 0, largest = 0;
  double best_profit = 0.00;
  for (int i = 0; i < N; ++i) {

    int lo = i+1, hi = N-1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if ((elves[mid].first-elves[i].first) <= D) {
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }

    int group_ends = hi;
    if (group_ends > last_end) {
      groups++;
      int len = group_ends - i + 1;
      if (len > largest) largest = len;
      double profit = acm[group_ends];
      if (i) profit -= acm[i-1];
      if (profit > best_profit) best_profit = profit;
      last_end = group_ends;
    }
  }

  cout << groups;
  cout << " " << largest;
  cout << " " << fixed << setprecision(2) << best_profit << "\n";

  return 0;
}
