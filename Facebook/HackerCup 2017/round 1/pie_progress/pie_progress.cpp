#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 9;
const int MAXM = 1 << 9;

int64 C[MAXN][MAXM];

int N, M;

char last_cached[MAXN][MAXN], cached_now;
int64 cache[MAXN][MAXN];

int64 solve(int day, int pies) {
  int rem = N - day;
  if (pies >= rem) return 0LL;

  int64 &res = cache[day][pies];
  if (last_cached[day][pies] == cached_now) return res;
  last_cached[day][pies] = cached_now;

  res = -1LL;
  if (pies) {
    res = solve(day+1, pies-1);
  }

  int64 acm = 0LL;
  for (int p = 1; p <= M; ++p) {
    acm += C[day][p-1];
    int64 cur = acm + 1LL * p * p + solve(day + 1, pies - 1 + p);
    if (res == -1LL) res = cur;
    res = min(res, cur);
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> C[i][j];
      }
      sort(C[i], C[i]+M);
    }

    cached_now++;
    cout << "Case #" << tc << ": " << solve(0, 0) << "\n";
  }

  return 0;
}
