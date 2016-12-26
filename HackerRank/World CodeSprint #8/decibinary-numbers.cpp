#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAX_BIT = 18;
const int MAX_DECIMAL = 285112;

char cached[MAX_BIT + 1][MAX_DECIMAL + 1];
int64 cache[MAX_BIT + 1][MAX_DECIMAL + 1];

int64 acm[MAX_DECIMAL + 1];

int pw[MAX_BIT + 1];

int64 count(int x, int bit = MAX_BIT) {
  if (bit < 0) return (x == 0) ? 1 : 0;

  int64 &res = cache[bit][x];
  if (cached[bit][x]) return res;
  cached[bit][x] = 1;

  res = 0LL;
  for (int dig = 0; dig < 10; ++dig) {
    if (pw[bit]*dig <= x) res += count(x - pw[bit]*dig, bit-1);
  }

  return res;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  for (int i = 0; i <= MAX_BIT; ++i) pw[i] = 1<<i;

  acm[0] = 0LL;
  for (int decimal = 0; decimal <= MAX_DECIMAL; ++decimal) {
    if (decimal) acm[decimal] = acm[decimal-1];
    acm[decimal] += count(decimal);
  }

  int q;
  cin >> q;
  while (q--) {
    int64 x; cin >> x;

    int lo = 0, hi = MAX_DECIMAL - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (acm[mid] >= x) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    x -= (lo ? acm[lo-1] : 0LL);

    int decimal = lo;
    int64 res = 0LL;

    for (int bit = MAX_BIT; bit >= 0; --bit) {
      for (int dig = 0; dig < 10; ++dig) {
        if (count(decimal - pw[bit]*dig, bit-1) >= x) {
          res = 10LL*res + dig;
          decimal -= pw[bit] * dig;
          break;
        } else {
          x -= count(decimal - pw[bit]*dig, bit-1);
        }
      }
    }

    cout << res << "\n";
  }

  return 0;
}
