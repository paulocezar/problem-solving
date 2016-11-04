#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char cached[2048][2048];
uint64 dp[2048][2048], m;

uint64 solve(int rem, int opn) {
  if (rem == 0) return ((opn == 0) ? 1ULL : 0ULL);
  uint64 &r = dp[rem][opn];
  if (cached[rem][opn]) return r;
  cached[rem][opn] = 1;
  r = solve(rem-1, opn+1);
  if (opn) {
    r += solve(rem-1, opn-1);
    if (r > m) r = m;
  }
  return r;
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> m;

  int opn = 0;
  uint64 nd = m;
  for (int i = 0; i < n; ++i) {
    uint64 cnt = solve(n-1-i, opn + 1);
    if (cnt >= nd) {
      opn++;
      cout << "(";
    } else {
      nd -= solve(n-1-i, opn + 1);
      opn--;
      cout << ")";
    }
  }
  cout << "\n";

  return 0;
}
