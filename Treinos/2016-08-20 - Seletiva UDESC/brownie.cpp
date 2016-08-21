#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int p; int64 b;
    cin >> p >> b;
    int m; cin >> m;
    cout << "Seletiva #" << t << ":\n";
    while (m--) {
      cin >> p;
      while (b <= p) {
        b *= 2LL;
      }
      b -= p;
      cout << b << "\n";
    }
    cout << "\n";
  }



  return 0;
}
