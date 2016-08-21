#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-2, -2, +2, +2, -1, -1, +1, +1};
int dy[] = {-1, +1, -1, +1, -2, +2, -2, +2};

int dist[32][32];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, R1, C1, R2, C2;
    cin >> N >> R1 >> C1 >> R2 >> C2;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        dist[i][j] = -1;
      }
    }

    dist[R1][C1] = 0;
    queue< pair<int,int> > q;
    q.push(make_pair(R1, C1));
    while (!q.empty()) {
      R1 = q.front().first, C1 = q.front().second; q.pop();
      if (R1 == R2 && C1 == C2) break;
      for (int mv = 0; mv < 8; ++mv) {
        int nr = R1 + dx[mv];
        int nc = C1 + dy[mv];
        if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
        if (dist[nr][nc] == -1) {
          dist[nr][nc] = dist[R1][C1] + 1;
          q.push(make_pair(nr, nc));
        }
      }
    }
    cout << "Caso #" << t << ": " << dist[R2][C2] << "\n";
  }

  return 0;
}
