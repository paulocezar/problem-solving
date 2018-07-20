#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 18;
const int MAXV = 1 << 17;
const int MOD = 1'000'000'007;

template<int M>
struct ModInt {
  static const int Mod = M;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  int get() const { return (int)x; }

  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};

using mint_t = ModInt<MOD>;
using result_t = tuple<mint_t,mint_t,mint_t>;

array<vector<int>, MAXN> gr;
array<int, MAXN> c;
array<mint_t, MAXV> fib;

result_t doit(int u, int pa = -1) {
  mint_t res = fib[c[u]],
         sum_f = fib[c[u]],
         sum_f_minus = fib[c[u]-1];

  for (int v : gr[u]) {
    if (v == pa) continue;
    mint_t r, s, s_m;
    tie(r, s, s_m) = doit(v, u);

    res += r;
    res += ((sum_f_minus * s_m) + (sum_f * s)) * 2;

    sum_f += fib[c[u]-1] * s_m + fib[c[u]] * s;
    sum_f_minus += fib[c[u]-2] * s_m + fib[c[u]-1] * s;
  }

  return result_t{res, sum_f, sum_f_minus};
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int mx = 2;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i]; c[i] += 2;
    mx = max(mx, c[i]);
  }

  fib[0] = 1, fib[1] = 0;
  for (int i = 2; i <= mx; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  mint_t res;
  tie(res, ignore, ignore) = doit(1);

  cout << res.get() << "\n";

  return 0;
}
