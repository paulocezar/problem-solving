#include <bits/stdc++.h>

#include "message.h"
#include "winning_move.h"

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

  int N = GetNumPlayers();

  int lo, hi;
  tie(lo, hi) = find_shard(N, _id, _nodes);

  if (lo >= hi) {
    PutInt(0, 0);
    Send(0);
    return 0;
  }

  if (_id) {
    map<int64, int> cnt;
    for (int i = lo; i < hi; ++i) {
      cnt[GetSubmission(i)]++;
    }

    int will_send = 0;
    for (auto &ntry : cnt) {
      if (ntry.second == 1) {
        will_send++;
      } else {
        will_send += 2;
      }
    }

    PutInt(0, will_send);
    for (auto &ntry : cnt) {
      if (ntry.second == 1) {
        PutLL(0, ntry.first);
      } else {
        PutLL(0, ntry.first);
        PutLL(0, ntry.first);
      }
    }
    Send(0);

  } else {
    map<int64, int> cnt;
    for (int i = lo; i < hi; ++i) {
      cnt[GetSubmission(i)]++;
    }

    for (int slave = 1; slave < _nodes; ++slave) {
      int node = Receive(-1);
      int sz = GetInt(node);
      while (sz--) {
        cnt[GetLL(node)]++;
      }
    }

    int64 winner = 0LL;
    for (auto &ntry : cnt) {
      if (ntry.second == 1) {
        winner = ntry.first;
        break;
      }
    }

    cout << winner << endl;
  }

  return 0;
}
