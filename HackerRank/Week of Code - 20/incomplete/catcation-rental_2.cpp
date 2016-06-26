#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class segtree {
  int len, _from, _to, _with;
  vector<int> tree, lazy;

  void _push(int node, bool leaf) {
    if (!lazy[node]) return;

    if (!leaf) {
      int ls = (node<<1) + 1;
      int rs = ls + 1;
      lazy[ls] = max(lazy[ls], lazy[node]);
      lazy[rs] = max(lazy[rs], lazy[node]);
    }
    tree[node] = max(tree[node], lazy[node]);
    lazy[node] = 0;
  }

  void _update(int node, int lo, int hi) {
    if (_from <= lo && hi <= _to) {
      lazy[node] = max(lazy[node], _with);
      _push(node, lo == hi);
      return;
    }

    int mid = (lo + hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;

    _push(node, lo==hi);
    _push(ls, lo == mid);
    _push(rs, (mid+1)==hi);

    if (mid >= _from) _update(ls, lo, mid);
    if ((mid+1) <= _to) _update(rs, mid+1, hi);

    tree[node] = max(tree[ls], tree[rs]);
  }

  int _get_max(int node, int lo, int hi) {
    _push(node, lo==hi);
    if (_from <= lo && hi <= _to) return tree[node];

    int mid = (lo + hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;

    int ans = 0;
    if (mid >= _from) ans = max(ans, _get_max(ls, lo, mid));
    if ((mid+1) <= _to) ans = max(ans, _get_max(rs, mid+1, hi));
    return ans;
  }

public:
  segtree(int _len) : len(_len) {
    this->tree = vector<int>(4*len, 0);
    this->lazy = vector<int>(4*len, 0);
  };

  void update(int from, int to, int with) {
    _from = from, _to = to, _with = with;
    _update(0, 1, len);
  }

  int get_max(int from, int to) {
    _from = from, _to = to;
    return _get_max(0, 1, len);
  }
};

class bit {
  int max_val;
  vector<int> nodes;
  void _add(int idx, int val) {
    while (idx <= max_val) {
      nodes[idx] += val;
      idx += (idx & -idx);
    }
  }

  int _get(int idx) {
    int res = 0;
    while (idx > 0) {
      res += nodes[idx];
      idx -= (idx & -idx);
    }
    return res;
  }
public:
  bit(int len) : max_val(len) {
    this->nodes = vector<int>(max_val+10, 0);
  }

  void add(int from, int to, int val) {
    _add(from, val);
    _add(to+1, -val);
  }

  int get(int at) {
    return _get(at);
  }
};

struct reservation_t {
  int lo, hi, id;
  bool operator <(const reservation_t &r) const {
    return lo == r.lo ?
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, D, K;
  cin >> N >> D >> K;

  segtree busy(D);
  bit ans(D);

  vector<reservation_t> reservations(N);
  for (int i = 0; i < N; ++i) {
    cin >> reservations[i].lo >> reservations[i].hi;
    reservations[i].id = i;
  }
  sort(reservations.begin(), reservations.end());

  int lo, hi, len, mx;
  for (int i = 0; i < N; ++i) {
    lo = reservations[i].lo, hi = reservations[i].hi;
    len = hi-lo+1;
    mx = busy.get_max(lo, hi);
    if ((mx+1) <= len) {
      ans.add(mx+1, len, len);
      busy.update(lo, hi, len);
    }
  }

  for (int i = 0; i < K; ++i) {
    cin >> lo;
    cout << ans.get(lo) << "\n";
  }

  return 0;
}
