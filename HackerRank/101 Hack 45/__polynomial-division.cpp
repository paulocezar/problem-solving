#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
const int MOD = 1e9 + 7;

int c[MAXN], ax[MAXN];

int fpw(int64 a, int b = MOD-2) {
  int64 r = 1;
  while (b > 0) {
    if (b & 1) { r *= a; r %= MOD; }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return r;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, a, b, q;
  cin >> n >> a >> b >> q;
  int ia = fpw(a);

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int i, x; cin >> i >> x; c[i] = x;
    } else {
      int l, r;
      cin >> l >> r;
      int len = r-l+1;
      for (int i = 0; i < len; ++i) ax[i] = c[l+i];

      bool ok = false;
      for (int p = len-1; p > 0; --p) {
        int64 xx = (1LL * ax[p] * ia) % MOD;
        ax[p-1] -= (xx * b) % MOD; ax[p-1] %= MOD; ax[p-1] = (ax[p-1] + MOD) % MOD;
      }
      if (p[0] == 0LL) cout << "YES\n";
      else cout << "NO\n";
    }
  }


  return 0;
}
