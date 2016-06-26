#include <bits/stdc++.h>

#include "message.h"
#include "oops.h"

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

inline pair<int, int> find_shard(int total, int id, int nodes) {
  auto f = [&](int node) { return min(node * ((total + nodes - 1) / nodes), total); };
  return make_pair(f(id), f(id+1));
}

int main() {

  int _nodes = NumberOfNodes();
  int _id = MyNodeId();

  int N = GetN();

  int lo, hi;
  tie(lo, hi) = find_shard(N, _id, _nodes);

  if (lo >= hi) return 0;

  int64 mn = GetNumber(lo), mx = GetNumber(lo);
  for (int i = lo+1; i < hi; ++i) {
    int64 cur = GetNumber(i);
    mn = min(mn, cur);
    mx = max(mx, cur);
  }

  if (_id) {
    Receive(_id-1);
    int64 v1 = GetLL(_id-1);
    int64 v2 = GetLL(_id-1);
    mn = min(mn, min(v1, v2));
    mx = max(mx, max(v1, v2));
  }

  if (hi == N) {
    cout << mx - mn << endl;
  } else {
    PutLL(_id+1, mn);
    PutLL(_id+1, mx);
    Send(_id+1);
  }

  return 0;
}
