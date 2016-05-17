#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) cin >> el;

    sort(a.begin(), a.end());

    int ans = 2e9;
    do {
      int cur = a[0] ^ a[1];
      for (int i = 1; i < n; ++i) {
        cur = max(cur, a[i-1] ^ a[i]);
      }
      ans = min(ans, cur);
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << "\n";
    return 0;
}
