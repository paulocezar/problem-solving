#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef double TYPE;
const TYPE EPS = 1e-9, INF = 1e9;

inline int sgn(TYPE a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(TYPE a, TYPE b) { return sgn(a - b); }

struct pt {
    TYPE x, y;
    pt(TYPE x = 0, TYPE y = 0) : x(x), y(y) { }

    bool operator==(pt p) { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
    bool operator<(pt p) const {
        return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0;
    }
    bool operator<=(pt p) { return *this < p || *this == p; }
    TYPE operator||(pt p) { return x*p.x + y*p.y; }
    TYPE operator%(pt p) { return x*p.y - y*p.x; }
    pt operator~() { return pt(x, -y); }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    pt operator*(pt p) { return pt(x*p.x - y*p.y, x*p.y + y*p.x); }
    pt operator/(TYPE t) { return pt(x/t, y/t); }
    pt operator/(pt p) { return (*this * ~p)/(p||p); }
};

const pt I = pt(0,1);
const double PI = acos(-1.0);

TYPE norm(pt a) { return a||a; }
TYPE abs(pt a) { return sqrt(a||a); }
TYPE dist(pt a, pt b) { return abs(a - b); }
TYPE area(pt a, pt b, pt c) { return (a-c)%(b-c); }
int ccw(pt a, pt b, pt c) { return sgn(area(a, b, c)); }
pt unit(pt a) { return a/abs(a); }
double arg(pt a) { return atan2(a.y, a.x); }
pt f_polar(TYPE mod, double ang) { return pt(mod * cos(ang), mod * sin(ang)); }
inline int g_mod(int i, int n) { if(i == n) return 0; return i; }

ostream& operator<<(ostream& o, pt p) {
    return o << "(" << p.x << "," << p.y << ")";
}

TYPE angle(pt a, pt b) {
  return atan2(a%b, a||b) * 180.0 / PI;
}

vector< pt > pts;

const int MAXN = 2318;
TYPE ang[MAXN][MAXN];
int ids[MAXN][MAXN];
int wr[MAXN][MAXN];
int N;

int doit(int B, int C) {
  int p = wr[C][B];
  TYPE lmt = ang[B][C] + 90.0;
  if (cmp(lmt, 360.0) >= 0) lmt -= 360.0;

  int as = 0, lo, hi, beg;
  if (cmp(lmt, ang[B][C]) < 0) {
    as += N - 2 -  p;
    lo = 0, hi = p-1;
    beg = 0;
  } else {
    lo = p+1, hi = N-2;
    beg = p+1;
  }

  while (lo <= hi) {
    int mid = (lo+hi) >> 1;
    if (cmp(ang[B][ids[B][mid]], lmt) <= 0) {
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }

  if (beg <= hi) as += hi - beg + 1;
  return as;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> N;
  pts.resize(N);

  for (auto &p : pts) {
    cin >> p.x >> p.y;
  }

  for (int i = 0; i < N; ++i) {
    int p = 0;
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      TYPE ax = angle(pts[i]-pts[j], pts[i]-pts[(i==0) ? 1 : 0]);
      if (cmp(ax, EPS) < 0) ax += 360.0;
      ang[i][j] = ax;
      ids[i][p++] = j;
    }

    sort(ids[i], ids[i]+p, [&](int a, int b) {
      return cmp(ang[i][a], ang[i][b]) < 0;
    });

    for (int j = 0; j < p; ++j) {
      wr[ids[i][j]][i] = j;
    }
  }

  int ans = 0;
  for (int B = 0; B < N; ++B) {
    for (int C = B+1; C < N; ++C) {
      if (B == C) continue;
      int as = doit(B, C);
      int ds = doit(C, B);
      ans += as * ds;
    }
  }
  cout << ans << "\n";

  return 0;
}
