#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 1e9 + 7;
const int64 INV2 = 500000004LL;

const int MAXN = 1 << 20;

int64 a[MAXN];


int64 fpw(int x) {
  int64 res = 1;
  int64 a = 2LL;
  while (x > 0) {
    if (x & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a; a %= MOD;
    x >>= 1;
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int64 res = 0LL;
  int64 ml = (fpw(n) - 1LL + MOD) % MOD;
  stack<int64> decr;

  for (int i = 0; i < n; ++i) {
    res += (ml * a[i]) % MOD;
    res %= MOD;
    if (((i+1)<<1) == n) continue;
    if (i < ((n-1)/2)) {
      int64 inc = (((fpw(n-i-2) - fpw(i))%MOD) + MOD) % MOD;
      ml += inc; ml %= MOD;
      decr.push(inc);
    } else if ((i+1) < n) {
      ml -= decr.top(); decr.pop();
      ml = ((ml % MOD) + MOD) % MOD;
    }
  }
  cout << res << "\n";

  return 0;
}

  // for (int n = 1; n <= 10; ++n) {
  //   vector<vector<int>> cnt(n, vector<int>(n, 0));
  //   for (int len = 1; len <= n; ++len) {
  //     for (int beg = 0; beg+len <= n; ++beg) {
  //       int end = beg + len - 1;
  //       int l = beg;
  //       int r = n - end - 1;
  //       int ways_l = l ? (1<<(l-1)) : 1;
  //       int ways_r = r ? (1<<(r-1)) : 1;
  //       ways_l *= ways_r;
  //       for (int i = beg; i <= end; ++i) cnt[i][len-1] += ways_l;
  //     }
  //   }

  //   vector<int> tms;
  //   for (auto &vv : cnt) {
  //     int ml = 1, tm = 0;
  //     for(int &v : vv) tm += (ml++) * v;
  //     tms.push_back(tm);
  //   }
  //   for (int i = 1; i < n; ++i) cout << tms[i] - tms[i-1] << " ";
  //   cout << "\n";
  // }
  // return 0;
