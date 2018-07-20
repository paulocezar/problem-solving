#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1 << 20;

char has_a[MAXV], has_b[MAXV];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    has_a[ai] = 1;
    mx = max(mx, ai);
  }

  for (int i = 0; i < n; ++i) {
    int bi;
    cin >> bi;
    has_b[bi] = 1;
    mx = max(mx, bi);
  }

  int res = 0;
  int gcd = mx;
  while (gcd) {
    int founda = 0, foundb = 0;
    for (int i = mx/gcd; (!founda || !foundb) && i >= 1; --i) {
      if (!founda && has_a[i*gcd]) founda = i * gcd;
      if (!foundb && has_b[i*gcd]) foundb = i * gcd;
    }
    if (founda && foundb) {
      res = founda + foundb;
      break;
    }
    gcd--;
  }
  cout << res << "\n";

  return 0;
}
