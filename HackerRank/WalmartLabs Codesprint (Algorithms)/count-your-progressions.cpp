#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 18;
const int MAXV = 1 << 7;
const int MOD = 1e9 + 9;

int a[MAXN];
int cnt[MAXV];
int pa[MAXV][2 * MAXV];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int res = n + 1;

  for (int i = 0; i < n; ++i) {
    for (int D = -100; D <= 100; ++D) {
      int prev = a[i] + D;
      if (prev < 1 || prev > 100) continue;
      pa[a[i]][MAXV + D] += pa[prev][MAXV + D];
      pa[a[i]][MAXV + D] += cnt[prev];
      pa[a[i]][MAXV + D] %= MOD;
    }
    cnt[a[i]]++;
  }

  for (int i = 1; i <= 100; ++i) {
    for (int D = -100; D <= 100; ++D) {
      res += pa[i][MAXV + D];
      res %= MOD;
    }
  }

  cout << res << "\n";

  return 0;
}
