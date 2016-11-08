#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int a, b, d;
    cin >> a >> b >> d;

    int r1 = d / b;
    int rm = d % b;
    if (rm) {
      if (r1 || (rm == a)) r1++;
      else r1 += 2;
    }

    int r2 = d / a;
    if (d % a) r2 += (r2 ? 1 : 2);

    r1 = min(r1, r2);

    cout << r1 << "\n";
  }

  return 0;
}
