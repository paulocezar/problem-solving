
/* THANK YOU, https://gmplib.org/manual/C_002b_002b-Interface-General.html */

#include <bits/stdc++.h>
#include <gmpxx.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N, J;

mpz_class eval_mask(int mask, mpz_class base) {
  mpz_class result = 1;
  mpz_class run = base;
  for (int i = 1; i < (N-1); ++i) {
    if (mask & 1) result += run;
    mask >>= 1;
    run *= base;
  }
  result += run;
  return result;
}

string jamcoin(int mask) {
  ostringstream ax;
  ax << bitset<32>(mask);
  string core = ax.str().substr(34-N);
  return "1" + core + "1";
}

mpz_class find_div(mpz_class num) {
  mpz_class gc1, gc2, ret1 = 2, ret2 = sqrt(num);

  int KEEP_TRYIN = 1337;
  while (--KEEP_TRYIN) {
    gc1 = gcd(num, ret1);
    gc2 = gcd(num, ret2);

    if (gc1 == ret1 || gc2 == ret2) break;

    mpz_nextprime(ret1.get_mpz_t(), ret1.get_mpz_t());
    mpz_nextprime(ret2.get_mpz_t(), ret2.get_mpz_t());
  }
  if (gc1 == ret1) return gc1;
  return gc2;
}

void gen() {
  int lim = 1<<(N-2);
  int created = 0;

  for (int mask = 0; mask < lim; ++mask) {

    bool ok = true;
    vector<mpz_class> cert;
    for (int i = 2; i <= 10; ++i) cert.push_back(mpz_class(i));
    for (mpz_class &base : cert) {
      mpz_class cur = eval_mask(mask, base);
      if (mpz_probab_prime_p(cur.get_mpz_t(), 42)) { ok = false; break; }
      base = find_div(cur);
      if (base == mpz_class(1)) { ok = false; break; }
    }

    if (ok) {

      cout << jamcoin(mask);

      for (const mpz_class &dv : cert) {
        cout << " " << dv.get_str();
      }
      cout << endl;

      created++;
      if (created == J) return;
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T; cin >> T;

  cin >> N >> J;

  cout << "Case #1:\n";
  gen();

  return 0;
}
