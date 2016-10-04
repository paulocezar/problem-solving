#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXP = 31623;
const int SQMP = 178;

vector<int> primes;
bitset<MAXP> bs;

void sieve() {
  primes.clear();
  for (int i = 0; i < MAXP; ++i) bs[i] = i & 1;
  bs[1] = 0;
  bs[2] = 1;
  for (int i = 3; i < SQMP; i += 2) {
    if (bs[i]) {
      for (int j = i*i; j < MAXP; j += i) {
        bs[j] = 0;
      }
    }
  }

  primes.clear();
  for (int i = 1; i < MAXP; ++i) if (bs[i]) {
    primes.push_back(i);
  }
}

int factors(int x) {
  int res = 0;

  for (int i = 0; primes[i]*primes[i] <= x; ++i) {
    if (x % primes[i]) continue;
    res++;
    while (!(x % primes[i])) x /= primes[i];
  }

  if (x > 1) res++;

  return res;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  sieve();

  int n;
  cin >> n;

  int64 res = 0LL;
  for (int k = 4; k <= n; ++k) {
    int fs = factors(k);
    int64 cur = ((1LL << fs) - 2LL) / 2LL;
    res += cur;
  }

  cout << res << "\n";

  return 0;
}
