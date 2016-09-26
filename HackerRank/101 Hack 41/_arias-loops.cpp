#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 1e9 + 7;


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 n, k;
  cin >> n >> k;

  if (k == 1LL) cout << n << "\n";
  else {
    k--;
    int64 c = (k * (k + 1LL)) / 2LL;
    int64 mxi = n - c;
    int64 ans = 0LL;
    for (int64 i = 1LL; i <= mxi; ++i) {
      int64 cur = 1LL;
      for (int64 j = 1LL; j <= k; ++j) {
        int64 ths = n - ((j*(j+1LL))/2LL) - i + 1LL;
        cur *= (ths % MOD);
        cur %= MOD;
      }
      ans += cur;
      ans %= MOD;
    }
    cout << ans << "\n";
  }


  return 0;
}
