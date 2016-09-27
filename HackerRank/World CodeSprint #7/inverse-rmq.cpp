#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 18;

int segt[4 * MAXN];
set<int> with_cnt[32];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  map<int, int> cnt;

  int nn = (n << 1) - 1;
  for (int i = 0; i < nn; ++i) {
    int ax; cin >> ax;
    cnt[ax]++;
  }

  int mxcnt = 0;

  while ((1<<mxcnt) <= n) {
    with_cnt[++mxcnt].clear();
  }

  for (auto &e : cnt) {
    if (e.second <= mxcnt) {
      with_cnt[e.second].insert(e.first);
    }
  }

  int idx = 0;
  int should_have = 1;

  if (int(with_cnt[mxcnt].size()) == 1) {
    while (idx < nn) {
      if (with_cnt[mxcnt].empty()) {
        mxcnt--;
        if (int(with_cnt[mxcnt].size()) != should_have) {
          break;
        }
        should_have <<= 1;
      }
      int cur = -1;
      bool ok = true;

      if (idx) {
        int pa = segt[(idx-1)>>1];
        auto nxt = with_cnt[mxcnt].lower_bound(pa);
        if (nxt != with_cnt[mxcnt].end()) {
          cur = *nxt;
        } else {
          ok = false;
        }
      } else cur = *with_cnt[mxcnt].begin();

      if (!ok) {
        break;
      }

      with_cnt[mxcnt].erase(cur);

      int node = idx;
      while (node < nn) {
        segt[node] = cur;
        node = (node << 1) + 1;
      }

      idx += 2;
    }
  }

  if (idx < nn) cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < nn; ++i) {
      cout << segt[i] << " \n"[i==(nn-1)];
    }
  }

  return 0;
}
