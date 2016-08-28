#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int mtx[2*128][2*128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    for (int i = 0; i < 2*n; ++i) {
      for (int j = 0; j < 2*n; ++j) {
        cin >> mtx[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cur = mtx[i][j];
        cur = max(cur, mtx[2*n - i - 1][j]);
        cur = max(cur, mtx[i][2*n - j - 1]);
        cur = max(cur, mtx[2*n - i - 1][2*n - j - 1]);
        ans += cur;
      }
    }
    cout << ans << "\n";

  }

  return 0;
}
