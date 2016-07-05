#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int x[1<<17];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  map<int, int> pa;
  map<int, int> tree;

  cin >> x[0];
  tree[x[0]] = 3;

  for (int i = 1; i < N; ++i) {
    cin >> x[i];
    auto bgr = tree.upper_bound(x[i]);
    if (bgr != tree.begin()) {
      auto sml = bgr; sml--;
      if (sml->second & 2) {
        pa[x[i]] = sml->first;
        sml->second ^= 2;
      } else {
        pa[x[i]] = bgr->first;
        bgr->second ^= 1;
      }
    } else {
      pa[x[i]] = bgr->first;
      bgr->second ^= 1;
    }
    tree[x[i]] = 3;
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int qq; cin >> qq;
    cout << pa[x[qq-1]] << (Q ? " " : "\n");
  }

  return 0;
}
