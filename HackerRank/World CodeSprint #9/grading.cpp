#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int g; cin >> g;
    int up = ((g / 5) + 1) * 5;
    if (g >= 38 && (up - g) < 3) g = up;
    cout << g << "\n";
  }

  return 0;
}
