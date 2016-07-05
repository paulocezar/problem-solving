#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1000;

bitset< MAXN+1 > bs;
vector< int > primes;

void sieve() {
    for (int i = 0; i <= MAXN; ++i) bs[i] = i&1;
    bs[1] = false;
    bs[2] = true;
    primes.push_back(2);
    for (int i = 3; i <= MAXN; i += 2) if (bs[i]) {
      primes.push_back(i);
      for (int j = i*i; j <= MAXN; j += i) bs[j] = false;
    }
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  sieve();

  int N, M;
  cin >> N >> M;
  auto p1 = upper_bound(primes.begin(), primes.end(), N);
  auto p2 = upper_bound(primes.begin(), primes.end(), M);
  p1--; p2--;
  cout << (*p1) * (*p2) << "\n";

  return 0;
}
