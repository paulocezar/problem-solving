#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int64> a(n);
    for (auto &el : a) cin >> el;

    sort(a.begin(), a.end());

    int x = -1, y = -1, z = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        for (int k = j+1; k < n; ++k) {
          if (((a[i] + a[j]) > a[k]) && ((a[i]+a[j]+a[k]) >= (x+y+z))) {
            x = a[i], y = a[j], z = a[k];
          }
        }
      }
    }

    cout << x;
    if (x > 0) cout << " " << y << " " << z;
    cout << "\n";

    return 0;
}
