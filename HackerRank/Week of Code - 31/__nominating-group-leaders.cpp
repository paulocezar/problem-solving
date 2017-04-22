#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

struct query_t {
  int l, r, x, id;
};

int v[MAXN], ans[MAXN], cnt[MAXN];
query_t q[MAXN];

set<int> with_cnt[MAXN];

void add(int val, int chng) {
  if (cnt[val]) with_cnt[cnt[val]].erase(val);
  cnt[val] += chng;
  if (cnt[val]) with_cnt[cnt[val]].insert(val);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cnt[i] = 0;
      with_cnt[i+1].clear();
      cin >> v[i];
    }

    int g;
    cin >> g;

    for (int i = 0; i < g; ++i) {
      cin >> q[i].l >> q[i].r >> q[i].x;
      q[i].id = i;
    }

    int SQ = (int)sqrt((double)n);
    sort(q, q+g, [&SQ](const query_t &a, const query_t &b) -> bool {
      int aa = a.l / SQ;
      int bb = b.l / SQ;
      return (aa == bb) ? (a.r < b.r) : (aa < bb);
    });

    int curL = q[0].l, curR = q[0].l;
    add(v[curL], 1);

    for (int i = 0; i < g; ++i) {
      while (q[i].l < curL) add(v[--curL], 1);
      while (q[i].l > curL) add(v[curL++], -1);
      while (q[i].r > curR) add(v[++curR], 1);
      while (q[i].r < curR) add(v[curR--], -1);
      int res = -1;
      if (!with_cnt[q[i].x].empty()) {
        res = *with_cnt[q[i].x].begin();
      }
      ans[q[i].id] = res;
    }

    for (int i = 0; i < g; ++i) cout << ans[i] << "\n";
  }

  return 0;
}
