#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  bool ok = false;
  while (k--) {
    cin >> n;
    if (s[n-1] == '0') ok = true;
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";


  return 0;
}
