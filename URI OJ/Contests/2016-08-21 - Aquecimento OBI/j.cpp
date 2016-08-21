#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 128;

int N, K;
int grid[MAXN][MAXN];

int cache[MAXN][MAXN][32][16];
char cached[MAXN][MAXN][32][16];

int doit(int i, int j, int mask, int imune) {
  if ((i >= N) || (j >= N) || (grid[i][j] == 32)) return -1e9;
  if ((i == (N-1)) && (j == (N-1))) return 0;

  int &ret = cache[i][j][mask][imune];
  if (cached[i][j][mask][imune]) return ret;
  cached[i][j][mask][imune] = 1;

  if (grid[i][j] > 0) {
    mask |= grid[i][j];
    if (mask == 31) {
      return ret = max(doit(i+1, j, 0, K), doit(i, j+1, 0, K));
    } else {
      int ni = max(imune-1, 0);
      return ret = max(doit(i+1, j, mask, ni), doit(i, j+1, mask, ni));
    }
  }

  int c = imune ? 0 : grid[i][j];
  int ni = max(imune - 1, 0);
  ret = -1e9;
  int nxt = max(c + doit(i+1, j, mask, ni), c + doit(i, j+1, mask, ni));
  return ret = max(ret, nxt);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      string cur;
      cin >> cur;
      switch (cur[0]) {
        case 'P': grid[i][j] = 1; break;
        case 'O': grid[i][j] = 2; break;
        case 'W': grid[i][j] = 4; break;
        case 'E': grid[i][j] = 8; break;
        case 'R': grid[i][j] = 16; break;
        case '#': grid[i][j] = 32; break;
        case 'I':
        case 'F': grid[i][j] = 0; break;
        default: grid[i][j] = -stoi(cur);
      }
    }
  }

  int ans = doit(0, 0, 0, 0);

  if (ans == -1e9) cout << "-1\n";
  else cout << 1-ans << "\n";

  return 0;
}
