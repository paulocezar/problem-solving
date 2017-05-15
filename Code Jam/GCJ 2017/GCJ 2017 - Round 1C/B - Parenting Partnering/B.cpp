#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int DAY = 1440;
using sched = bitset<DAY>;

sched busy[2];

int cache[2][DAY/2 + 1][DAY];
int last_cached[2][DAY/2 + 1][DAY], cached_now;


int solve(int who, int free_time, int cur) {
  if (free_time < 0) return 2e9;

  if (cur == DAY) {
    if (free_time) return 2e9;
    return who ? 1 : 0;
  }

  int &res = cache[who][free_time][cur];
  int &lc = last_cached[who][free_time][cur];
  if (lc == cached_now) return res;
  lc = cached_now;

  res = 2e9;

  if (!busy[who][cur]) res = min(res, solve(who, free_time-(1-who), cur+1));
  if (!busy[1-who][cur]) res = min(res, 1 + solve(1-who, free_time-who, cur+1));

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {

    int A[2];
    for (int i = 0; i < 2; ++i) cin >> A[i];

    for (int i = 0; i < 2; ++i) {
      busy[i].reset();

      for (int j = 0; j < A[i]; ++j) {
        int s, e;
        cin >> s >> e;
        while (s < e) {
          busy[i][s] = 1;
          s++;
        }
      }
    }

    int res = 2e9;
    for (int s = 0; s < 2; ++s) {
      if (!busy[0][0]) {
        cached_now++;
        res = min(res, solve(0, 720, 0));
      }

      swap(busy[0], busy[1]);
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }

  return 0;
}
