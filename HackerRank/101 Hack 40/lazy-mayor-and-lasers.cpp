#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

int h[MAXN];
int x[MAXN];


int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> x[i]; x[i]--;
    }
    sort(x, x+m);

    int last_cut = -1;
    for (int i = 0; i < m; ++i) {
      int cur = x[i] - 1;
      int mx = 1;
      while (cur > last_cut) {
        h[cur] = min(h[cur], mx);
        cur--;
        mx++;
      }
      last_cut = x[i] - 1;
    }

    int64 sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += h[i];
    }

    cout << sum << "\n";

    return 0;
}
