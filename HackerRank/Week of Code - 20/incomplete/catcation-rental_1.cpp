#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class segtree {
  int len, _from, _to, _with;
  vector<int> tree, lazy;

  void _push(int node, int len) {
    if (!lazy[node]) return;

    if (len > 1) {
      int ls = (node<<1) + 1;
      int rs = ls + 1;
      lazy[ls] += lazy[node];
      lazy[rs] += lazy[node];
    }

    tree[node] += lazy[node];
    lazy[node] = 0;
  }

  void _update(int node, int lo, int hi) {
    if (_from <= lo && hi <= _to) {
      lazy[node]++;
      _push(node, hi-lo+1);
      return;
    }

    int mid = (lo + hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;

    _push(node, hi-lo+1);
    _push(ls, mid-lo+1);
    _push(rs, hi-mid);

    if (mid >= _from) _update(ls, lo, mid);
    if (mid+1 <= _to) _update(rs, mid+1, hi);

    tree[node] = tree[ls] + tree[rs];
  }

  int _get(int node, int lo, int hi) {
    _push(node, hi-lo+1);
    if (_from <= lo && hi <= _to) return tree[node];

    int mid = (lo + hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;

    int ans = 0;
    if (mid >= _from) ans += _get(ls, lo, mid);
    if (mid+1 <= _to) ans += _get(rs, mid+1, hi);
    return ans;
  }

public:
  segtree(int _len) : len(_len) {
    int lg = 0;
    while ((1<<lg) < _len) ++lg;
    lg++;

    tree.resize(1<<lg);
    lazy.resize(1<<lg);
  };

  void clear() {
    for (int i = 0, sz = tree.size(); i < sz; ++i) tree[i] = lazy[i] = 0;
  }

  void update(int from, int to, int with) {
    _from = from, _to = to, _with = with;
    _update(0, 1, len);
  }

  int get(int from, int to) {
    _from = from, _to = to;
    return _get(0, 1, len);
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, D, K;
  cin >> N >> D >> K;

  segtree busy(D);
  vector<int> lo(N), hi(N);

  for (int i = 0; i < N; ++i) {
    cin >> lo[i] >> hi[i];
  }

  int di;
  for (int j = 0; j < K; ++j) {
    if (j) busy.clear();
    cin >> di;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int len = hi[i]-lo[i]+1;
      if (len >= di) {
        int occupied = busy.get(lo[i], hi[i]);
        if (!occupied) {
          ans += len;
          busy.update(lo[i], hi[i], 1);
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
