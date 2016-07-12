#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline bool covered(int &a, pair<int,int> &b) {
  return b.first <= a && a <= b.second;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> cov;
    for (int i = 0; i < n; ++i) {
      int ax; cin >> ax;
      if (ax) {
        cov.push_back({max(0,i-k+1),min(n-1,i+k-1)});
      }
    }

    int cur = 0;
    int pos = 0;
    int sz = cov.size();
    int ans = 0;

    while ((pos < sz) && (cur < n)) {
      int far = cur;
      bool ok = false;
      while ((pos < sz) && covered(cur, cov[pos])) {
        far = max(far, cov[pos].second);
        ok = true;
        pos++;
      }
      if (ok) {
        cur = far+1;
        ans++;
      } else break;
    }

    if (cur < n) ans = -1;
    cout << ans << "\n";

    return 0;
}
