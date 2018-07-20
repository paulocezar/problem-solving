#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1'000'000;
const int MAXN = 100'000;

bitset<MAXV + 1> active;
array<int, MAXN + 1> a;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> intervals;
  int beg = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];

    if (active[a[i]]) intervals.emplace_back(i-1, beg);

    while (active[a[i]]) {
      active[a[beg]] = 0;
      beg++;
    }
    active[a[i]] = 1;
  }
  intervals.emplace_back(n, beg);

  int l, r;
  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(l, 0));
    int64_t res = 0;

    int last_end = l - 1;
    while (it != intervals.end() && it->second <= r) {
      int new_ends = min(r, it->first) - last_end;
      int beginings = last_end - max(it->second, l) + 1;
      int64_t crossing = beginings * new_ends;
      int64_t contained = 1LL * new_ends * (new_ends + 1) / 2LL;
      res += crossing + contained;
      last_end = min(r, it->first);
      it++;
    }
    cout << res << "\n";
  }

  return 0;
}
