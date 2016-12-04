#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 11;
const int MOD = 1e9 + 7;

int a[MAXN];
int cache[2][MAXN][MAXN];
char cached[2][MAXN][MAXN];

int solve(int prev_repeated, int uniq, int repeated) {
  if (uniq == 0 && repeated == 0) return 1;

  int &res = cache[prev_repeated][uniq][repeated];
  char &is_cached = cached[prev_repeated][uniq][repeated];

  if (!is_cached) {
    res = 0;

    int ml = uniq;
    if (prev_repeated) ml--;
    if (ml > 0) {
      res = (int64(ml) * solve(0, uniq-1, repeated)) % MOD;
    }

    if (repeated) {
      res += (int64(repeated) * solve(1, uniq+1, repeated-1)) % MOD;
      if (res >= MOD) res -= MOD;
    }

    is_cached = 1;
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a, a+n);
    int uniq = 0, repeated = 0;

    for (int i = 0; i < n; ++i) {
      if (((i+1) < n) && (a[i+1] == a[i])) {
        repeated++;
        i++;
      } else uniq++;
    }

    cout << solve(0, uniq, repeated) << "\n";
  }

  return 0;
}
