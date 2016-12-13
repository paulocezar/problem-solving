#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
const int SQMN = 317;

bitset< MAXN > bs;
vector<int> primes;

void sieve() {
  for (int i = 1; i < MAXN; ++i) bs[i] = i & 1;
  bs[1] = 0;
  bs[2] = 1;
  for (int i = 3; i <= SQMN; i += 2) {
    if (bs[i]) {
      for (int j = i*i; j <= MAXN; j += i) bs[j] = false;
    }
  }

  primes.clear();
  for (int i = 2; i < MAXN; ++i) if (bs[i]) {
    primes.push_back(i);
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  sieve();
  int g;
  cin >> g;
  while (g--) {
    int n;
    cin >> n;
    int pp = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    cout << ((pp & 1) ? "Alice" : "Bob") << "\n";
  }

  return 0;
}
