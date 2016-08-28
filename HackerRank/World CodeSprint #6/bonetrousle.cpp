#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool can_do(int64 val, int64 lim, int64 with) {
  if (with == 0LL) return val == 0LL;
  if (with > lim) return false;
  int64 mn = ((1LL + with) * with) / 2LL;
  if (val < mn) return false;
  return (((2LL * val)+with-1LL) / with) <= (2LL*lim-with+1LL);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int64 n, k, b;
    cin >> n >> k >> b;
    if (can_do(n, k, b)) {
      int64 mn = ((1LL+b) * b) / 2LL;
      while (b) {
        mn -= b;
        int64 cur = min(n - mn, k);
        k = cur - 1LL;
        n -= cur;
        cout << cur;
        b--;
        if (b) cout << " ";
      }
      cout << "\n";
    } else cout << "-1\n";
  }

  return 0;
}
