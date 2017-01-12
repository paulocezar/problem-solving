#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

double angle(int X, int Y) {
  double r = atan2(50 * X, 50 * Y) * 180 / M_PI;
  if (r < -1e-6) r += 360;
  return r;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int P, X, Y;
    cin >> P >> X >> Y; X -= 50, Y -= 50;
    string res = "white";

    int d = X * X + Y * Y;
    if (d <= 2500 && P && 100*angle(X, Y) <= P*360 ) {
      res = "black";
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }

  return 0;
}
