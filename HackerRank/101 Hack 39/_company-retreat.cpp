#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod =1e9 + 7;

vector<int> gr[1<<17];

int cur_day, day_lm;

int last_cached[2048][2048];
int cache[2048][2048];

int doit(int u, int lm) {
  int &res = cache[u][lm];
  if (last_cached[u][lm] == cur_day) return res;
  last_cached[u][lm] = cur_day;

  int sum = 0;
  for (int &v : gr[u]) {
    sum += doit(v, day_lm);
  }

  res = sum + 1;

  if (lm > 1) {
    for (int &v : gr[u]) {
      int nw = doit(v, day_lm);
      int cn = doit(v, lm-1);
      res = min(res, sum  - nw + cn);
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; ++i) {
      int ax; cin >> ax;
      gr[ax].push_back(i);
    }

    int64 ans = 0, day_cs;
    for (cur_day = 1; cur_day <= m; ++cur_day) {
      cin >> day_cs >> day_lm;
      day_lm = min(day_lm, n);
      int cur = doit(1, day_lm);

      ans += (int64(cur) * day_cs) % mod;
      ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}
