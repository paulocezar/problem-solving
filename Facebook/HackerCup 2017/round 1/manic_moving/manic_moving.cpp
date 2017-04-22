#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int INF = 1e9;
const int MAXN = 1 << 7;
const int MAXK = 1 << 13;

int S[MAXK], D[MAXK];

int dist[MAXN][MAXN];
int64 cache[2][MAXN][MAXK];
char last_cached[2][MAXN][MAXK], cached_now;

int K;

int64 solve(int at, int lowest_loaded, int loaded_next) {

  if (lowest_loaded == K) {
    if (dist[at][D[K]] == INF) return -1LL;
    return dist[at][D[K]];
  }

  int64 &res = cache[loaded_next][at][lowest_loaded];
  if (last_cached[loaded_next][at][lowest_loaded] == cached_now) return res;
  last_cached[loaded_next][at][lowest_loaded] = cached_now;
  res = -1LL;

  if (!loaded_next && (dist[at][S[lowest_loaded+1]] != INF)) {
    res = solve(S[lowest_loaded+1], lowest_loaded, 1);
    if (res >= 0LL) res += dist[at][S[lowest_loaded+1]];
  }

  if (dist[at][D[lowest_loaded]] != INF) {
    int64 nxt = -1LL;

    if (loaded_next) {
      nxt = solve(D[lowest_loaded], lowest_loaded+1, 0);
    } else if (dist[D[lowest_loaded]][S[lowest_loaded+1]] != INF) {
      nxt = solve(S[lowest_loaded+1], lowest_loaded+1, 0);
      if (nxt >= 0LL) nxt += dist[D[lowest_loaded]][S[lowest_loaded+1]];
    }

    if (nxt >= 0LL) {
      nxt += dist[at][D[lowest_loaded]];
      if (res == -1LL) res = nxt;
      res = min(res, nxt);
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, M;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        dist[i][j] = INF;
      }
      dist[i][i] = 0;
    }

    int u, v, c;
    while (M--) {
      cin >> u >> v >> c;
      dist[u][v] = min(dist[u][v], c);
      dist[v][u] = dist[u][v];
    }

    for (int i = 1; i <= K; ++i) {
      cin >> S[i] >> D[i];
    }

    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          if (dist[i][j] > (dist[i][k] + dist[k][j])) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }

    cached_now++;
    int64 res = -1LL;
    if (dist[1][S[1]] != INF) {
      res = solve(S[1], 1, 0);
      if (res >= 0LL) res += dist[1][S[1]];
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }

  return 0;
}
