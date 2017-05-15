#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int Hd, Ad, Hk, Ak, B, D;

int last_cached[128][128][128][128], cached_now;
int cache[128][128][128][128];

int solve(int h, int he, int bf, int dbf) {
  if (he <= 0) return 0;
  if (h <= 0 || bf > 111 || dbf > 111) return 1e9;

  int &res = cache[h][he][bf][dbf];
  int &lc = last_cached[h][he][bf][dbf];
  if (lc == cached_now) return res;
  lc = cached_now;

  int d = max(0, Ak - dbf * D);
  int dd = Ad + bf * B;
  res = 1e9;
  res = min(res, 1 + solve(Hd - d, he, bf, dbf));
  res = min(res, 1 + solve(h - d, he - dd, bf, dbf));
  if (B) res = min(res, 1 + solve(h - d, he, bf+1, dbf));
  d = max(0, d - D);
  if (D) res = min(res, 1 + solve(h - d, he, bf, dbf + 1));
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
    cached_now++;
    int r = solve(Hd, Hk, 0, 0);
    cout << "Case #" << tc << ": ";
    if (r == 1e9) cout << "IMPOSSIBLE\n";
    else cout << r << "\n";
  }

  return 0;
}
