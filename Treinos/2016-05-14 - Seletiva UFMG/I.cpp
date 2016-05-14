#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-9;

int cmp(double a, double b = 0.0){
  if ((a - b) > EPS) return 1;
  if ((b - a) > EPS) return -1;
  return 0;
}

struct pt {
  double x, y;

  pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  double len() { return sqrt(x * x + y * y); }
  double len2() { return x * x + y * y; }

  pt normalize() { return (*this)/len(); }

  pt operator - (pt p) { return pt(x - p.x, y - p.y); }
  pt operator + (pt p) { return pt(x + p.x, y + p.y); }
  pt operator * (double k) { return pt(x * k, y * k); }
  pt operator / (double k) { return pt(x / k, y / k); }

  bool operator < (const pt& p) const {
    if (cmp(x, p.x)) return x > p.x;
    return y < p.y;
  }

  bool operator == (const pt p){
    return (!cmp(x, p.x) && !cmp(y, p.y));
  }
};

double dist(pt a, pt b) { return (a - b).len(); }
double dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

int side_sign(pt a, pt b, pt c){
  return cmp(cross(a - c, b - c));
}

pt closest_point(pt a, pt b, pt c){
  if (side_sign(a, b, c) == 0) return c;
  pt dir = b - a;
  return a + (dir * dot(dir, c - a) / dir.len2());
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  pt A, B, S;
  cin >> A.x >> A.y >> B.x >> B.y >> S.x >> S.y;

  double v1 = 2*(B.x-A.x), v2 = 2*(B.y-A.y), v3 = B.x*B.x + B.y*B.y - A.x*A.x - A.y*A.y;
  pt p1(1, (v3 - v1) / v2);
  pt p2(2, (v3 - 2.0*v1) / v2);

  pt res = closest_point(p1, p2 , S);

  cout << fixed << setprecision(2) << res.x << " " << res.y << "\n";

  return 0;
}
