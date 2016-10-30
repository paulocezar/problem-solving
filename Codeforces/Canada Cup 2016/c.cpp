#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char grid[2][13];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int ii = -1, jj = -1;

  for (int i = 0; ii == -1 && i < 27; ++i) {
    for (int j = i+2; ii == -1 && j < 27; ++j) {
      if (s[i] == s[j]) {
        ii = i, jj = j;
      }
    }
  }

  if (ii == -1) cout << "Impossible\n";
  else {
    int dist = jj - ii - 1;
    int up = dist / 2;
    int ax = ii + up;
    int i = 0, j = 12;

    int dir = -1;
    while (ax >= 0) {
      grid[i][j] = s[ax--];
      j += dir;
      if (j < 0) {
        i = 1;
        j = 0;
        dir = 1;
      }
    }

    ax = ii+up+1;
    i = 1, j = 12, dir = -1;
    while (ax < 27) {
      if (ax == jj) ax++;
      if (ax < 27) grid[i][j] = s[ax++];
      j += dir;
      if (j < 0) {
        i = 0;
        j = 0;
        dir = 1;
      }
    }

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 13; ++j) {
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }

  return 0;
}
