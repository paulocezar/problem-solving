#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int STEPS = 128;

const double EPS = 1e-9;
const double PI = acos(-1);
const int MAXN = 1 << 14;

inline int sgn(double a) {
  return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0)));
}

inline int cmp(double a, double b) {
  return sgn(a - b);
}

int L[MAXN];



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ml = 0, sm = 0;
  for (int i = 0; i < n; ++i) {
    cin >> L[i];
    ml = max(ml, L[i]);
    sm += L[i];
  }

  double lo = .5 * ml, hi = 2.0 * (sm - ml);
  while (STEPS--) {
    double mid = .5 * (lo + hi);

    double ev = 0.0;
    for (int i = 0; i < n; ++i) {
      ev += asin(L[i] / (2.0 * mid));
    }

    if (cmp(ev, PI) > 0) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << fixed << setprecision(6);

  double yc = .5 * L[0];
  double xc = fabs(sqrt(lo * lo - (yc * yc)));

  double xi = -xc;
  double yi = -yc;

  for (int i = 0; i < n; ++i) {
    cout << xi + xc << "\n";
    cout << yi + yc << "\n";
    cout << "\n";

    double theta_i = 2.0 * asin(L[i] / (2.0 * lo));

    double nxi = cos(theta_i) * xi + sin(theta_i) * yi;
    double nyi = -sin(theta_i) * xi + cos(theta_i) * yi;
    xi = nxi;
    yi = nyi;
  }

  return 0;
}
