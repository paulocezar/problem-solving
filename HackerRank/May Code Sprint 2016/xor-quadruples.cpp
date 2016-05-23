#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cnt[1<<12][1<<12];
int total[1<<12];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<int> els(4);
  for (auto &a : els) cin >> a;

  sort(els.begin(), els.end());

  for (int i = 1; i <= els[2]; ++i) {
    for (int j = i; j <= els[3]; ++j) {
      cnt[i][i ^ j]++;
    }
    total[i] = els[3] - i + 1;
  }

  for (int i = els[2]; i > 1; --i) {
    total[i-1] += total[i];
    for (int j = 0; j < 4096; ++j) {
      cnt[i-1][j] += cnt[i][j];
    }
  }

  int64 ans = 0;
  for (int i = 1; i <= els[0]; ++i) {
    for (int j = i; j <= els[1]; ++j) {
      ans += total[j] - cnt[j][i ^ j];
    }
  }

  cout << ans << "\n";

  return 0;
}
