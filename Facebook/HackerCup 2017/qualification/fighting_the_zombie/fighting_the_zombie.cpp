#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-9;

const int SGN(double a) {
  return ((a > EPS) ? 1 : ((a < -EPS) ? (-1) : 0));
}

const int CMP(double a, double b) {
  return SGN(a - b);
}

struct spell_t {
  int x, y, z;
  spell_t(vector<int> a = {0,0,0}) : x(a[0]), y(a[1]), z(a[2]) {}
};

spell_t parse(string s) {
  vector<int> v = {0, 0, 0};
  int i = 0, sgn = -1;
  for (char c : s) {
    if (isdigit(c)) {
      v[i] = 10*v[i] + int(c-'0');
    } else {
      i++;
      if (c == '-') sgn = 1;
    }
  }
  v[2] *= sgn;
  return spell_t(v);
}

double cache[32][32][1<<15];
char cached[32][32][1<<15];

double solve(int sides, int rem, int need) {
  if (rem >= need) return 1.0;
  if (rem*sides < need) return 0.0;

  double &res = cache[sides][rem][need];
  if (cached[sides][rem][need]) return res;
  cached[sides][rem][need] = 1;

  res = 0.0;
  for (int i = 1; i <= sides; ++i) {
    res += solve(sides, rem-1, max(0, need-i));
  }
  res /= sides;

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cout << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int H, S;
    cin >> H >> S;

    spell_t spell[S];
    for (int i = 0; i < S; ++i) {
      string s; cin >> s;
      spell[i] = parse(s);
    }

    double res = 0.0;
    for (int i = 0; i < S; ++i) {
      double cur = solve(spell[i].y, spell[i].x, max(0, H + spell[i].z));
      if (CMP(cur, res) > 0) res = cur;
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }

  return 0;
}
