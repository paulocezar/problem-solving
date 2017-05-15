#include <bits/stdc++.h>

#include "message.h"
#include "todd_and_steven.h"

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

inline pair<int, int> find_shard(int total, int id, int nodes) {
  auto f = [&](int node) { return min(node * ((total + nodes - 1) / nodes), total); };
  return make_pair(f(id), f(id+1));
}

typedef const function<int64(int64)>& value_getter;
typedef const function<int64()>& length_getter;

const int64 MOD = 1000000007LL;

int64 doit(int _nodes, int _id,
          value_getter mine, length_getter mylen,
          value_getter other, length_getter otherlen) {

  int N = mylen();

  auto smaller_than = [&other](int64 val, int lo, int hi) -> int64 {
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (other(mid) < val) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  };

  int lo, hi;
  tie(lo, hi) = find_shard(N, _id, _nodes);

  if (lo >= hi) return 0LL;

  int ol = otherlen();
  int l = 0, r = ol - 1;
  l = smaller_than(mine(lo), 0, r);
  l = min(l, ol - 1);
  r = smaller_than(mine(hi-1), l, r);
  r = min(r, ol - 1);

  int64 ret = 0LL;

  for (int i = lo; i < hi; ++i) {
    int64 cur = mine(i);
    int nl = smaller_than(cur, l, r);
    l = max(l, nl);
    int64 real_pos = i + nl;
    ret += (cur ^ real_pos);
    ret %= MOD;
  }

  return ret;
}

int main() {

  int _nodes = NumberOfNodes();
  int _id = MyNodeId();

  int64 steven = GetStevenLength();
  int64 todd = GetToddLength();
  int64 total = steven + todd;

  int todd_nodes = max(1LL, (todd * _nodes) / total);
  int steven_nodes = _nodes - todd_nodes;

  int64 myval = 0LL;

  if (_id < todd_nodes) {
    myval = doit(todd_nodes, _id,
                 GetToddValue, GetToddLength,
                 GetStevenValue, GetStevenLength);
  } else {
    myval = doit(steven_nodes, _id - todd_nodes,
                 GetStevenValue, GetStevenLength,
                 GetToddValue, GetToddLength);
  }

  if (_id) {
    PutLL(0, myval);
    Send(0);
  } else {
    for (int i = 1; i < _nodes; ++i) {
      Receive(i);
      int64 nxt = GetLL(i);
      myval += nxt;
      myval %= MOD;
    }
    cout << myval << "\n";
  }

  return 0;
}
