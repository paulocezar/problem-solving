#include <bits/stdc++.h>

using namespace std;

int x[1024];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, xx;
  cin >> n >> xx;

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    x[i] = abs(xx-x[i]);
  }

  int nn = 1e6, d = 1, idx = -1;
  for (int i = 0; i < n; ++i) {
    int v; cin >> v;
    if (x[i]*d < nn*v) {
      idx = i;
      nn = x[i], d = v;
    } else if (x[i]*d == nn*v) {
      idx = -1;
    }
  }

  cout << idx << "\n";

  return 0;
}
