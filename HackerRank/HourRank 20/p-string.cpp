#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'000'007;
const int MAXN = 500'000;

int64_t fpw(int64_t a, int b) {
  int64_t r = 1LL;
  while (b) {
    if (b & 1) { r *= a; r %= MOD; }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return r;
}

int64_t f[MAXN+1], invf[MAXN+1];

int64_t c(int n, int k) {
  if (k > n) return 0LL;
  return (((f[n] * invf[n-k])%MOD) * invf[k]) % MOD;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  f[0] = 1LL, invf[0] = 1LL;
  for (int i = 1; i <= MAXN; ++i) {
    f[i] = (int64_t(i) * f[i-1]) % MOD;
    invf[i] = fpw(f[i], MOD-2);
  }

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;

    vector<int> cnt(4, 0);
    for (char c : s) cnt[c-'a']++;

    auto doit = [&cnt] (int offset) {
      int mx = min(cnt[offset], cnt[offset+1]);
      int64_t str = 0LL;
      for (int n = 0; n <= mx; ++n) {
        str += (c(cnt[offset], n) * c(cnt[offset+1], n)) % MOD;
        if (str >= MOD) str -= MOD;
      }
      return str;
    };

    int64_t p1 = doit(0);
    int64_t p2 = doit(2);

    p1 *= p2; p1 %= MOD; p1 = (p1-1+MOD) % MOD;
    cout << p1 << "\n";
  }

  return 0;
}
