#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXD = 1 << 9;
int gr[MAXD][MAXD];
int acm[MAXD][MAXD];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, r;
  cin >> n >> m >> r;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> gr[i][j];
      acm[i][j] = j ? acm[i][j-1] : 0;
      acm[i][j] += gr[i][j];
    }
  }

  int rr = r * r;
  int res = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      int lox = max(x-r, 0), hix = min(x+r, n-1);
      int sm = 0;
      for (int a = lox; a <= hix; ++a) {
        int B = -2 * y;
        int C =  a*a - rr - 2*a*x + x*x + y*y;

        double v1 = .5 * (-B + sqrt(B*B - 4*C));
        double v2 = .5 * (-B - sqrt(B*B - 4*C));
        if (v1 > v2) swap(v1, v2);
        int loy = max(0, (int)ceil(v1));
        int hiy = min(m-1, (int)floor(v2));
        sm += acm[a][hiy] - (loy ? acm[a][loy-1] : 0);
      }
      res ^= sm;
    }
  }
  cout << res << "\n";

  return 0;
}
