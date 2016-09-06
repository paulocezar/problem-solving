#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string grid[64];

vector<pair<int,int>> candidates;

int n, csz;
int best = 2e9;

void doit(int pos, int cur, int need) {
  if (need == 0) {
    best = min(best, cur);
    return;
  }
  if (pos == csz || csz-pos < need || cur >= best) return;

  doit(pos+1, cur, need);
  int inc = 0;
  int i = candidates[pos].first;
  int j = candidates[pos].second;
  int ii = i;
  while (ii >= 0) {
    if (grid[ii][j] == '#') break;
    if (grid[ii][j] == 'o') inc++;
    ii--;
  }
  ii = i;
  while (ii < n) {
    if (grid[ii][j] == '#') break;
    if (grid[ii][j] == 'o') inc++;
    ii++;
  }
  int jj = j;
  while (jj >= 0) {
    if (grid[i][jj] == '#') break;
    if (grid[i][jj] == 'o') inc++;
    jj--;
  }
  jj = j;
  while (jj < n) {
    if (grid[i][jj] == '#') break;
    if (grid[i][jj] == 'o') inc++;
    jj++;
  }
  grid[i][j] = 'o';
  doit(pos+1, cur+inc, need-1);
  grid[i][j] = '.';
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '.') candidates.push_back({i,j});
    }
  }
  csz = candidates.size();
  random_shuffle(candidates.begin(), candidates.end());
  doit(0, 0, k);

  cout << best << "\n";

  return 0;
}
