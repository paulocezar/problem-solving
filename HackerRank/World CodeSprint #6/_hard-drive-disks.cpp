#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

pair<int,int> comp[MAXN];
unordered_map<int, int64> cache[MAXN];

int64 solve(int n, int k) {
  if (n < 0) return 0;
  if (k <= 0) return 2e10;
  if (cache[n].count(k)) return cache[n][k];
  int64 &res = cache[n][k];
  res = 2e10;
  vector<int64> xs;
  for (int i = n; i >= 0; --i) {
    xs.push_back(comp[i].first);
    xs.push_back(comp[i].second);
    sort(xs.begin(), xs.end());
    int64 mid = (xs[xs.size()/2] + xs[(xs.size()/2)-1]) / 2LL;
    int64 nw = 0LL;
    for (int64 &v : xs) {
      nw += abs(v-mid);
    }
    nw += solve(i-1, k-1);
    res = min(res, nw);
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> comp[i].first >> comp[i].second;
    if (comp[i].first < comp[i].second) swap(comp[i].first, comp[i].second);
  }
  sort(comp, comp+n);
  cout << solve(n-1, k) << "\n";

  return 0;
}
