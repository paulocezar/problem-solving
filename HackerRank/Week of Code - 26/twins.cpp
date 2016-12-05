#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int fpw(int64 a, int b, int n) {
  int64 ret = 1LL;
  while (b) {
    if (b & 1) ret = (a * ret) % n;
    a = (a * a) % n;
    b >>= 1;
  }
  return ret;
}

bool miller_rabin(int n, int base) {
  if (n <= 1) return false;
  if (n % 2 == 0) return n == 2;

  int s = 0, d = n - 1;
  while (d % 2 == 0) d /= 2, ++s;

  int base_d = fpw(base, d, n);
  if (base_d == 1) return true;
  int base_2r = base_d;

  for (int i = 0; i < s; ++i) {
    if (base_2r == 1) return false;
    if (base_2r == n - 1) return true;
    base_2r = (int64(base_2r) * int64(base_2r)) % n;
  }

  return false;
}

bool isprime(int n) {
    if (n == 2 || n == 7 || n == 61) return true;
    return miller_rabin(n, 2) && miller_rabin(n, 7) && miller_rabin(n, 61);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int res = 0;
  for (int i = n; i+2 <= m; ++i) {
    if (isprime(i) && isprime(i+2)) res++;
  }
  cout << res << "\n";

  return 0;
}
