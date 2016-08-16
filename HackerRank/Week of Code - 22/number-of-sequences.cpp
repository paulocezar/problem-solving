#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1e9 + 7;
const int MAXN = 1<<17;

bitset<MAXN> bs;
int xs[MAXN], n;

int getopts(int i, int opts) {
  if (xs[i] != -1) opts = 1;
  for (int j = 2*i; j <= n; j += i) {
    bs[j] = 0;
    if (xs[j] != -1) {
      int must = xs[j] % i;
      if (xs[i] != must) {
        if (xs[i] == -1) { opts = 1; xs[i] = must; }
        else { opts = 0; }
      }
    }
  }
  return opts;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 1; i <= n; ++i) { cin >> xs[i]; bs[i] = i & 1; }
  bs[2] = 1;

  int64 ans = 1LL;

  for (int i = 2; i <= n; ++i) {
    if (!bs[i]) continue;
    int opts = getopts(i, i);

    int64 cur = i;
    int64 fct = opts;
    while ((cur * int64(i)) <= int64(n)) {
      cur *= int64(i);
      opts = getopts(cur, i);
      fct *= int64(opts); fct %= mod;
    }
    ans *= fct;
    ans %= mod;
  }

  cout << ans << "\n";

  return 0;
}
