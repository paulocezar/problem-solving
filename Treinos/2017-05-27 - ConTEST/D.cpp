#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 100000;
const int SQMN = 317;
const int MOD = 1e9 + 7;

bitset<MAXN + 1> bs;

void sieve() {
  for (int i = 0; i <= MAXN; ++i) bs[i] = i & 1;
  bs[1] = 0; bs[2] = 1;

  for (int i = 3; i*i <= MAXN; ++i) if (bs[i]) {
    for (int j = i*i; j <= MAXN; j += i) {
      bs[j] = 0;
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  sieve();

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int64 n; cin >> n;
    int64 res = 1;
    for (int i = 2; i <= n; ++i) {
      if (bs[i]) {
        int64 p = i;
        int cnt = 0;

        while (n >= p) {
          cnt += n / p;
          p *= i;
        }

        res *= (cnt/2) + 1;
        res %= MOD;
      }
    }
    cout << "Caso " << tc << ": " << res << "\n";
  }

  return 0;
}
