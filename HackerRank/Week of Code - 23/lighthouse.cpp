#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string grid[n + 2];
  grid[0] = grid[n+1] = "**";
  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
    grid[i] = "*" + grid[i] + "*";
    grid[0] += "*";
    grid[n+1] += "*";
  }

  int r = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (grid[i][j] == '*') continue;

      int cur = 128 * 128;

      for (int ni = 0; ni <= n+1; ++ni) {
        for (int nj = 0; nj <= n+1; ++nj) {
          if (grid[ni][nj] == '.') continue;
          int di = abs(i-ni);
          int dj = abs(j-nj);
          int dd = di*di + dj*dj;
          cur = min(cur, dd);
        }
      }

      cur = max(cur - 1, 0);
      cur = sqrt(cur);

      r = max(r, cur);
    }
  }

  cout << r << "\n";

  return 0;
}
