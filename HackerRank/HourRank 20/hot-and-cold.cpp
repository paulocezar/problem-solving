#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int c1, c2, h1, h2;
  cin >> c1 >> c2 >> h1 >> h2;

  int lo = max(c1, c2);
  int hi = min(h1, h2);

  if (lo <= hi) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
