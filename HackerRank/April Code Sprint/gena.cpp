#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  unsigned origin = 0;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai; ai--;
    origin <<= 2;
    origin |= ai;
  }

  unordered_set<unsigned> seen;
  queue<unsigned> q;
  q.push(origin); seen.insert(origin);

  int depth = -1;

  while (!q.empty()) {
    depth++;
    if (seen.count(0u)) break;
    int sz = q.size();
    while (sz--) {
      unsigned u = q.front(); q.pop();
      unsigned ax = u;
      int cur = n-1;
      vector<int> top(4, 2e9);
      while (cur >= 0) {
        top[ax&3] = cur--;
        ax >>= 2;
      }
      for (unsigned i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 4; ++j) {
          if (top[i] < top[j]) {
            int pos = (n-1-top[i]) << 1;
            unsigned nxt = u & ~(3u<<pos);
            nxt |= (j << pos);
            if (seen.insert(nxt).second) q.push(nxt);
          }
        }
      }
    }
  }

  cout << depth << "\n";

  return 0;
}
