#include <bits/stdc++.h>

#include "message.h"
#include "weird_editor.h"

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

inline pair<int, int> find_shard(int total, int id, int nodes) {
  auto f = [&](int node) { return min(node * ((total + nodes - 1) / nodes), total); };
  return make_pair(f(id), f(id+1));
}

const int MAXS = 1 << 24;
const int64 MOD = 1000000007LL;

char digs[MAXS];
int pref[MAXS];

int64 fpw(int64 a, int64 b) {
  a %= MOD;
  int64 r = 1LL;
  while (b > 0LL) {
    if (b & 1LL) { r *= a; r %= MOD; }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return r;
}

int main() {

  int _nodes = NumberOfNodes();
  int _id = MyNodeId();

  int N = GetNumberLength();

  int lo, hi;
  tie(lo, hi) = find_shard(N, _id, _nodes);

  if (lo >= hi) return 0;

  int top = 0;
  for (int i = lo; i < hi; ++i) {
    char cur = GetDigit(i);
    while (top && (digs[top-1] < cur)) top--;
    pref[top] = ((10LL * (top ? pref[top-1] : 0LL)) + cur) % MOD;
    digs[top++] = cur;
  }

  int64 cur = 0LL;
  int len = 0;
  int highest = 0;

  if (hi == N) {
      cur = pref[top-1];
      len = top;
      highest = digs[0];
  } else {
    Receive(_id + 1);
    int64 nxt = GetLL(_id + 1);
    int nl = GetInt(_id + 1);
    char mx = GetInt(_id + 1);

    int lo = 0, hi = top-1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (digs[mid] < mx) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    if (hi >= 0) {
      cur = pref[hi];
      cur *= fpw(10, nl); cur %= MOD;
      cur += nxt; cur %= MOD;
      len = hi + nl + 1;
      highest = digs[0];
    } else {
      cur = nxt;
      len = nl;
      highest = mx;
    }
  }

  if (_id) {
    PutLL(_id - 1, cur);
    PutInt(_id - 1, len);
    PutInt(_id - 1, highest);
    Send(_id - 1);
  } else {
    int missing = N - len;
    cur *= fpw(10, missing); cur %= MOD;
    cout << cur << "\n";
  }

  return 0;
}
