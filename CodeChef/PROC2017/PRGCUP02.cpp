#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    array<int, 3> a;
    for (int& v : a) { cin >> v; v*=v; }
    sort(a.begin(), a.end());

    if (a[0]+a[1] == a[2] && __gcd(a[0], __gcd(a[1], a[2])) == 1) cout << "YES\n";
    else cout << "NO\n";
  }



  return 0;
}
