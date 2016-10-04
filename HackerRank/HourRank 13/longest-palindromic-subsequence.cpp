#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 12;

int cache[MAXN][MAXN];
int last_cached[MAXN][MAXN], cached_now;

char s[MAXN];

int solve(int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;

  int &res = cache[i][j];
  if (last_cached[i][j] == cached_now) return res;
  last_cached[i][j] = cached_now;

  res = max(solve(i+1, j), solve(i, j-1));
  if (s[i] == s[j]) res = max(res, 2 + solve(i+1, j-1));

  return res;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;

    string ss;
    cin >> ss;

    for (int i = 0; i < n; ++i) s[i] = ss[i];
    cached_now++;
    int first = solve(0, n-1);
    n++;
    int res = 0;

    for (int pref = 0; pref < n; ++pref) {
      for (int j = pref+1; j <= n; ++j) {
        s[j] = ss[j-1];
      }

      for (char c = 'a'; c <= 'z'; ++c) {
        s[pref] = c;
        cached_now++;
        int changed = solve(0, n-1);
        if (changed >= (first+k)) res++;
      }

      s[pref] = ss[pref];
    }

    cout << res << "\n";

  }

  return 0;
}
