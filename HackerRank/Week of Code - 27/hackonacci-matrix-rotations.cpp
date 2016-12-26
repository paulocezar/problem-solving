#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 11;
const int PERIOD = 7;

vector<int> hack = {1, 0, 1, 0, 0, 1, 1};

int mtx[MAXN][MAXN], rot[MAXN][MAXN], n;

void rotate() {
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      swap(rot[i][j], rot[j][i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; 2*j <= n; ++j) {
      swap(rot[i][j], rot[i][n-j+1]);
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int ij = ((i * j) % PERIOD);
      ij = (ij * ij)%PERIOD;
      ij = (ij - 1 + PERIOD) % PERIOD;
      mtx[i][j] = rot[i][j] = hack[ij];
    }
  }

  vector<int> ans(4, 0);
  for (int k = 1; k < 4; ++k) {
    rotate();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (rot[i][j] != mtx[i][j]) ans[k]++;
      }
    }
  }

  while (q--) {
    int ang; cin >> ang; ang %= 360;
    cout << ans[ang / 90] << "\n";
  }

  return 0;
}
