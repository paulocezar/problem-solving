#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<18;

int lvl[MAXN];
bool has_r[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int64 res = 0LL;

  int p;
  cin >> p;
  set<int> tree;
  tree.insert(p);

  for (int i = 1; i < n; ++i) {
    cin >> p;
    auto nxt = tree.upper_bound(p);

    bool f = false;
    if (nxt != tree.begin()) {
      auto prv = nxt; prv--;
      if (!has_r[*prv]) {
        f = true;
        lvl[p] = lvl[*prv] + 1;
        has_r[*prv] = true;
      }
    }

    if (!f) {
      lvl[p] = lvl[*nxt] + 1;
    }

    tree.insert(p);
    res += lvl[p];
  }

  cout << res << "\n";

  return 0;
}
