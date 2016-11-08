#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string grid[32];
char seen[32][32];

vector<pair<int,int>> dir = {{-1,0}, {0,+1}, {+1,0}, {0, -1}};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i <= n; ++i) seen[i][0] = seen[i][m+1] = 1;
  for (int j = 0; j <= m; ++j) seen[0][j] = seen[n+1][j] = 1;

  int i = n, j = 1, cnt = 0, d = 0;
  ostringstream buf;

  int total = n * m;
  while (true) {
    buf << grid[i-1][j-1];
    cnt++;
    if (cnt == total) break;
    seen[i][j] = 1;
    int ni = i + dir[d].first, nj = j + dir[d].second;
    while (seen[ni][nj]) {
      d++;
      if (d == 4) d = 0;
      ni = i + dir[d].first, nj = j + dir[d].second;
    }
    i = ni, j = nj;
  }

  int res = 0;
  int len = 0;
  for (char c : buf.str()) {
    if (c == '#') {
      if (len) res++;
      len = 0;
    } else {
      len++;
    }
  }
  if (len) res++;
  cout << res << "\n";

  return 0;
}
