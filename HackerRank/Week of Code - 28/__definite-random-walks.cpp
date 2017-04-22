#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
  int get() const { return (int)x; }
  unsigned inv() const {
    int b = Mod - 2;
    ModInt r = 1, pw = ModInt(*this);
    while (b > 0) {
      if (b & 1) r *= pw;
      pw *= pw;
      b >>= 1;
    }
    return (unsigned)r.get();
  }

  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { x = (unsigned long long)x * that.inv() % MOD; return *this; }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
};

typedef ModInt<998244353> mint_t;

const int MAXN = 1 << 16;
const int MAXM = 1 << 17;

int f[MAXN];
mint_t p[MAXN];
mint_t res[2][MAXN];

vector<int> point_to[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  mint_t p_ini = mint_t(1) / n;

  for (int i = 1; i <= n; ++i) {
    cin >> f[i];
    point_to[f[i]].push_back(i);
    res[0][i] = p_ini;
  }

  for (int j = 0; j < m; ++j) {
    int ax; cin >> ax;
    p[j] = ax;
  }

  int old = 0, cur = 1;

  for (int i = 0; i < k; ++i) {

    for (int j = 1; j <= n; ++j) {

      mint_t pp = p[0] * res[old][j];

      unordered_set<int> prev;
      for (int x : point_to[j]) prev.insert(x);

      for (int d = 1; d < m; ++d) {
        mint_t was_at;
        unordered_set<int> nxt;
        for (int x : prev) {
          was_at += res[old][x];
          for (int w : point_to[x]) nxt.insert(w);
        }
        pp += p[d] * was_at;

        if (nxt.empty()) break;
        else prev = nxt;
      }

      res[cur][j] = pp;
    }

    old = 1-old;
    cur = 1-cur;
  }


  for (int i = 1; i <= n; ++i) {
    cout << res[old][i].get() << "\n";
  }

  return 0;
}
