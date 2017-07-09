#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000;

int C[1024][1024];
int DP[1024][1024];

pair<int,int> Q[128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int M, mm = 0;
  cin >> M;

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    cin >> Q[tc].first >> Q[tc].second;
    mm = max(mm, Q[tc].first);
  }

  C[0][0] = 1LL;
  for (int i = 1; i <= mm; ++i) {
    C[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
  }

  DP[0][0] = 1;
  for (int P = 1; P <= mm; ++P) {
    for (int N = P*M; N <= mm; ++N) {
      for (int X = M; X <= (N + M - P*M); ++X) {
        DP[P][N] = (DP[P][N] + (1LL * C[N][X] * DP[P-1][N-X])%MOD)%MOD;
      }
    }
  }

  for (int tc = 1; tc <= T; ++tc) {
    cout << "Cenario " << tc << ": " << DP[Q[tc].second][Q[tc].first] << "\n";
  }

  return 0;
}
