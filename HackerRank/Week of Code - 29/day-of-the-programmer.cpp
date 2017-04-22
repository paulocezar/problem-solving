#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int TRANSITION = 1918;

int main(int argc, char* argv[]) {

  int y;
  cin >> y;

  bool leap = false;
  if (y < TRANSITION) {
    leap = (y % 4 == 0);
  } else if (y > TRANSITION) {
    leap = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
  }

  string ans = "13.09.";
  if (leap) ans = "12.09.";
  if (y == TRANSITION) ans = "26.09.";

  cout << ans << y << "\n";

  return 0;
}
