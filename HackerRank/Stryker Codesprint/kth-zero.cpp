#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int bit[MAXN], a[MAXN], n;

void incr(int idx, int amnt) {
  while (idx <= n) {
    bit[idx] += amnt;
    idx += (idx & -idx);
  }
}

int cnt(int idx) {
  int res = 0;
  while (idx > 0) {
    res += bit[idx];
    idx -= (idx & -idx);
  }
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 0) incr(i, +1);
  }

  int cmd, p, k;
  while (m--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> k;
      if (cnt(n) < k) cout << "NO\n";
      else {
        int lo = 1, hi = n;
        while (lo <= hi) {
          int mid = (lo + hi) >> 1;
          int cc = cnt(mid);
          if (cc < k) {
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        }
        cout << lo-1 << "\n";
      }
    } else {
      cin >> p >> k; p++;
      if (a[p] == 0) incr(p, -1);
      a[p] = k;
      if (a[p] == 0) incr(p, +1);
    }
  }

  return 0;
}
