#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 19;

array<int, MAXN> T, V;
array<int64_t, MAXN> cached;

int n;
int64_t solve(int at) {
  if (at == n) return 0;

  if (cached[at]) return cached[at];
  unordered_set<int> seen;
  int cost = V[at];
  int64_t res = cost + solve(at+1);
  seen.insert(T[at]);
  int nxt = at+1;

  while (nxt < n) {
    if (!seen.insert(T[nxt]).second) break;
    cost |= V[nxt];
    res = min(res, cost + solve(++nxt));
  }

  cached[at] = res;
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> T[i];
  for (int i = 0; i < n; ++i) cin >> V[i];
  T[n] = T[n-1]; V[n] = 0;

  if (n <= 50000) { cout << solve(0) << "\n"; return 0; }

  unordered_set<int> seen;
  int64_t res = 0;
  int cost = 0;
  int started_at = 0;
  for (int i = 0; i <= n; ++i) {
    if (seen.insert(T[i]).second) {
      cost |= V[i];
    } else {
      int j = started_at-1;
      int tail = 0;
      int can_remove = 0;
      while (j >= 0) {
        if (seen.insert(T[j]).second) {
          int ntail = tail | V[j];
          if ((ntail & cost) != ntail) break;
          tail = ntail;
          j--;
        } else break;
      }
      res -= tail;
      res += cost;

      started_at = i;
      cost = V[i];
      seen = {T[i]};
    }
  }

  cout << res << "\n";

  return 0;
}
