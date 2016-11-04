#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char seen[256][256];

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int R, C;
  cin >> R >> C;
  string grid[R];
  for (int i = 0; i < R; ++i) {
    cin >> grid[i];
  }

  int i = 0, j = 0;
  int res = 0;
  while (grid[i][j] != 'T') {
    if (seen[i][j]) {
      cout << "Lost\n";
      return 0;
    }

    seen[i][j] = 1;
    res++;
    switch (grid[i][j]) {
      case 'N': i--; break;
      case 'S': i++; break;
      case 'W': j--; break;
      case 'E': j++; break;
    }

    if (i < 0 || j < 0 || i >= R || j >= C) {
      cout << "Out\n";
      return 0;
    }
  }

  cout << res << "\n";

  return 0;
}
