#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int cur = 0;
  bool ok = true;

  for (int i = 0; i < n; ++i) {
    int t; string dir;
    cin >> t >> dir;

    if (cur == 0 && dir[0] != 'S') ok = false;
    else if (cur == 20000 && dir[0] != 'N') ok = false;

    switch (dir[0]) {
      case 'N':
        cur -= t;
        if (cur < 0) ok = false;
        break;
      case 'S':
        cur += t;
        if (cur > 20000) ok = false;
        break;
      case 'E': break;
      case 'W': break;
    }
  }

  if (cur != 0) ok = false;

  if (ok) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
