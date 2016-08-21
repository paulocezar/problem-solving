#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = { 0,+1, 0,-1};
int dy[] = {+1, 0,-1, 0};

int seen[16][16];
string mat[16][16];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int M, N, T = 0;
  while (cin >> N >> M && (M || N)) {
    T++;
    cout << "Matriz #" << T << ":\n";
    cout << "Original:\n";
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> mat[i][j];
        if (j) cout << " ";
        cout << mat[i][j];
        seen[i][j] = 0;
      }
      cout << "\n";
    }
    cout << "Minhoca:\n";
    int cnt = 0, total = M * N;
    int i = 0, j = 0, dir = 0;
    bool changed = false;
    while (cnt < total) {
      seen[i][j] = 1;
      if (changed) cout << "\n";
      changed = false;
      cout << mat[i][j]; cnt++;
      int tr = 0;
    doit:
      if (tr > 4) break;
      int ni = i + dx[dir], nj = j + dy[dir];
      if (0 <= ni && ni < N && 0 <= nj && nj < M && !seen[ni][nj]) {
        i = ni, j = nj;
      } else {
        changed = true;
        dir++;
        tr++;
        if (dir == 4) dir = 0;
        goto doit;
      }
    }
    cout << "\n\n";
  }

  return 0;
}
