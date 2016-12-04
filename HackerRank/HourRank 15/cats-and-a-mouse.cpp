#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    int da = abs(x-z);
    int db = abs(y-z);
    if (da < db) {
      cout << "Cat A\n";
    } else if (db < da) {
      cout << "Cat B\n";
    } else {
      cout << "Mouse C\n";
    }
  }

  return 0;
}
