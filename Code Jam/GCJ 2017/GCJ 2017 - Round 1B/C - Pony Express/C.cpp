#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 128;

int D[MAXN][MAXN];
int E[MAXN], S[MAXN];
int last_cached[MAXN][MAXN], cached_now;

double cache[MAXN][MAXN];
int N;

double solve(int at, int with_horse_from, int distance_walked) {
  if (at == N) return 0.0;

  double &res = cache[at][with_horse_from];
  int &lc = last_cached[at][with_horse_from];
  if (lc == cached_now) return res;

  res = double(D[at][at+1])/double(S[at]) + solve(at+1, at, D[at][at+1]);
  int nd = distance_walked+D[at][at+1];
  if (nd <= E[with_horse_from])
    res = min(res, double(D[at][at+1])/double(S[with_horse_from]) + solve(at+1, with_horse_from, nd));
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(13);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
      cin >> E[i] >> S[i];
    }

    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        cin >> D[i][j];
      }
    }

    cout << "Case #" << tc << ":";
    while (Q--) {
      int U, V; cin >> U >> V;
      cached_now++;
      cout << " " << (double(D[1][2]) / double(S[1])) + solve(2, 1, D[1][2]);
    }
    cout << "\n";
  }

  return 0;
}
