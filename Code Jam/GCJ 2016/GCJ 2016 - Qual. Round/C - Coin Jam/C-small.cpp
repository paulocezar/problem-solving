#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAX_PRIME int64(1e8)
#define SQ_MAX_PRIME int64(1e4)

bitset< MAX_PRIME + 1 > not_prime;
vector<int64> primes;

void sieve() {
    not_prime[1] = 1;
    for (int i = 4; i <= MAX_PRIME; i += 2) not_prime[i] = 1;

    for (int i = 3; i <= SQ_MAX_PRIME; i += 2) {
        if (not_prime[i]) continue;
        for (int j = i*i; j <= MAX_PRIME; j += i) not_prime[j] = 1;
    }

    primes.push_back(2LL);
    for (int i = 3; i <= MAX_PRIME; i+=2) {
        if (not_prime[i]) continue;
        primes.push_back(i);
    }
}

int64 prime_fact(int64 x) {
    if (x <= MAX_PRIME && !not_prime[x]) return x;
    for (const int64 &p : primes) {
        if ((x % p) == 0) return p;
        if (p > (x/p)) break;
    }
    return x;
}

int N, J;

int64 eval(int mask, int64 base) {
  int64 result = 1LL;
  int64 run = base;
  for (int i = 1; i < (N-1); ++i) {
    if (mask & 1) result += run;
    mask >>= 1;
    run *= base;
  }
  result += run;
  return result;
}

void gen() {
  int lim = 1<<(N-2);
  int created = 0;

  for (int mask = 0; mask < lim; ++mask) {
    bool ok = true;

    vector<int64> cert = {2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int64 &base : cert) {
      int64 cur = eval(mask, base);
      base = prime_fact(cur);
      if (base == cur) { ok = false; break; }
    }

    if (ok) {

      cout << "1"<< bitset<14>(mask) << "1";

      for (const int64 &dv : cert) {
        cout << " " << dv;
      }
      cout << "\n";

      created++;
      if (created == J) return;
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T; cin >> T;

  cin >> N >> J;

  sieve();
  cout << "Case #1:\n";
  gen();

  return 0;
}
