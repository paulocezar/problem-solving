#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  double x, y, a, b;
  cin >> x >> y >> a >> b;

  double a1 = -b;
  double b1 = a;

  double k = (x*b1 - a1*y) / (a*b1 - a1*b);
  double n = (a*y - x*b) / (a*b1 - a1*b);

  cout << fixed << setprecision(13);
  cout << k << "\n" << n << "\n";

  return 0;
}
