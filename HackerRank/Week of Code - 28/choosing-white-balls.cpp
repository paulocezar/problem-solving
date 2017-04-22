#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-9;

int sgn(double a) {
  return (a > EPS) ? 1 : ((a < -EPS) ? -1 : 0);
}

int cmp(double a, double b) {
  return sgn(a - b);
}

const int SPLIT = 25;

char cached[1 << SPLIT];
double small_cache[1 << SPLIT];
unordered_map<int, double> big_cache;

int ones = 0, n, k;

double solve(int bm) {
  if (k == 0) {
    return ones - __builtin_popcount(bm);
  }

  if (n < SPLIT) {
    if (cached[bm]) return small_cache[bm];
  } else {
    if (big_cache.count(bm)) return big_cache[bm];
  }

  double nxt[n];
  n--, k--;
  for (int i = 0; i <= n; ++i) {
    nxt[i] = solve(((bm >> (i+1)) << i) | (((1 << i) - 1) & bm));
  }
  n++, k++;

  double res = 0.0;

  for (int i = 0; i < n; ++i) {
    int j = n - 1 - i;
    if (i == j) {
      res += nxt[i];
    } else {
      if (cmp(nxt[i], nxt[j]) > 0) {
        res += nxt[i];
      } else {
        res += nxt[j];
      }
    }
  }

  res /= n;
  if (n < SPLIT) {
    small_cache[bm] = res;
    cached[bm] = 1;
  } else {
    big_cache[bm] = res;
  }
  return res;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  cin >> n >> k;
  string s;
  cin >> s;

  int bm = 1 << n;
  ones = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') {
      ones++;
      bm |= 1 << i;
    }
  }

  cout << fixed << setprecision(13) << solve(bm) << "\n";
  return 0;
}
