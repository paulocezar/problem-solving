#include <bits/stdc++.h>

#include "message.h"
#include "pancakes.h"

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

  int N = GetStackSize();

  int lo, hi;
  tie(lo, hi) = find_shard(N, _id, _nodes);

  if (lo >= hi) {
    PutInt(0, -1);
    Send(0);
    return 0;
  }

  int inc = 1;
  int first = GetStackItem(lo);
  int prev = first;
  for (int i = lo+1; i < hi; ++i) {
    int cur = GetStackItem(i);
    if (cur < prev) inc++;
    prev = cur;
  }

  if (_id) {
    PutInt(0, first);
    PutInt(0, prev);
    PutInt(0, inc);
    Send(0);
  } else {
    for (int node = 1; node < _nodes; ++node) {
      Receive(node);
      int nl = GetInt(node);
      if (nl == -1) continue;
      int nr = GetInt(node);
      int ns = GetInt(node);

      inc += ns;
      if (nl >= prev) inc--;
      prev = nr;
    }

    cout << inc << "\n";
  }

  return 0;
}
