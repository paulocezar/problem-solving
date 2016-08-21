#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double PI = 3.14159265358979;


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T, L, R;
  cin >> T;
  while (T--) {
    cin >> L >> R;
    double area;
    if (2*R <= L) {
      area = PI * R * R;
    } else if (2*R*R >= L*L) {
      area = L*L;
    } else {
      double a = sqrt(double(R*R) - double(L*L)/4.0);
      area = 0.5 * a * L;
      double ang = acos((.5*L)/double(R));
      ang = 0.5 * PI - 2.0*ang;
      double sector =  0.5 * R * R * ang;
      area = 4.0 * (area + sector);
    }
    cout << fixed << setprecision(2) << area << "\n";
  }

  return 0;
}
