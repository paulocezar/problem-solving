#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-9;

inline int SGN(double a) { return (a < -EPS) ? (-1) : ((a > EPS) ? 1 : 0); }
inline int CMP(double a, double b) { return SGN(a-b); }

struct pt {

  double x, y;

  pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  double len2() { return x * x + y * y; }

  pt operator - (pt p) { return pt(x - p.x, y - p.y); }
  pt operator + (pt p) { return pt(x + p.x, y + p.y); }
  pt operator * (double k) { return pt(x * k, y * k); }
  pt operator / (double k) { return pt(x / k, y / k); }
};

double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

inline int side_sign(pt a, pt b, pt c) { return SGN(cross(a - c, b - c)); }

struct square_t {

  pt p1, p2, p3, p4;

  square_t(pt a, pt b) {
    pt md = (a + b) / 2.0;
    p1 = a;
    p2 = p1 - md; swap(p2.x, p2.y); p2.y = -p2.y; p2 = p2 + md;
    p3 = b;
    p4 = p3 - md; swap(p4.x, p4.y); p4.y = -p4.y; p4 = p4 + md;
  }

  bool contains(pt p) {
    return side_sign(p1, p, p2) >= 0 &&
    side_sign(p2, p, p3) >= 0 &&
    side_sign(p3, p, p4) >= 0 &&
    side_sign(p4, p, p1) >= 0;
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int w, h;
  cin >> w >> h;

  pt c; double r;
  cin >> c.x >> c.y >> r; r *= r;

  pt a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  square_t sq(a, b);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      pt p(j, i);
      if (CMP((p - c).len2(), r) <= 0 || sq.contains(p)) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }

  return 0;
}
