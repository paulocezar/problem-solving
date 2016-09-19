#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n; cin >> n;
    if (n & 1) cout << "No\n";
    else cout << "Yes\n";
  }


  return 0;
}
