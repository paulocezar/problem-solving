#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> dir = {{-1, -1}, {-1, 0}, {-1, 1},
                             { 0, -1},          { 0, 1},
                             { 1, -1}, { 1, 0}, { 1, 1}};

int n, m, k;
string grid[1024];

int doit(int i, int j, int d, int h = 1) {
  if (h == k) return true;
  int ni = i + dir[d].first, nj = j + dir[d].second;
  if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == grid[i][j]) {
    return doit(ni, nj, d, h+1);
  }
  return false;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }

    string pm = "OX";
    vector<bool> p = {false, false};

    for (int c = 0; c < 2; ++c) {
      for (int i = 0; !p[c] && i < n; ++i) {
        for (int j = 0; !p[c] && j < m; ++j) {
          if (grid[i][j] == pm[c]) {
            for (int d = 0; !p[c] && d < int(dir.size()); ++d) {
              int best = 0;
              switch (d) {
                case 0: best = min(i+1, j+1); break;
                case 1: best = i+1; break;
                case 2: best = min(i+1, m-j); break;
                case 3: best = j+1; break;
                case 4: best = m-j; break;
                case 5: best = min(n-i, j+1); break;
                case 6: best = n-i; break;
                case 7: best = min(n-i, m-j); break;
              }
              p[c] = (best >= k) && doit(i, j, d);
            }
            if (!p[c]) grid[i][j] = '-';
          }
        }
      }
    }

    if (p[0] == p[1]) cout << "NONE\n";
    else if (p[0]) cout << "WIN\n";
    else cout << "LOSE\n";
  }

  return 0;
}
