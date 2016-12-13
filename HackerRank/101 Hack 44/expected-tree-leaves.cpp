#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 17;

// int n;
// int solve(int leaves, int rem) {
//   if (!rem) return leaves;
//   if (cache[leaves].count(rem)) return cache[leaves][rem];

//   int non_leaf = n - (rem + leaves);
//   int res = (int64(leaves) * solve(leaves, rem-1)) % MOD;
//   if (non_leaf) {
//     res += int64(non_leaf) * solve(leaves+1, rem-1) % MOD;
//     if (res >= MOD) res -= MOD;
//   }
//   return cache[leaves][rem] = res;
// }
//
//  --->  https://oeis.org/A001710

int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  a[0] = a[1] = a[2] = 1;
  for (int i = 3; i <= n; ++i) {
    a[i] = (int64(i) * a[i-1]) % MOD;
  }

  cout << (int64(a[n]) * int64(n)) % MOD << "\n";

  return 0;
}
