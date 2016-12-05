#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 20;

int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int m, mn, mx;
  cin >> m >> mn >> mx;

  a[0] = a[1] - mx;
  a[n+1] = a[n] + mx;

  auto is_solution = [&m,mn,mx](int walked, int before, int after) -> pair<bool,int> {
    int rem = m - walked;

    if (rem == 0) return {true, 0}; // we're DONE!
    // no can do
    if (((before+after) < rem) || (rem < mn) || (rem > (2*mx))) return {false, 0};
    // mn <= rem
    if (rem <= mx) {
      if (rem <= after) return {true, 0};
      if (rem <= before) return {true, rem};
    }
    // mx < rem <= 2*mx, need to use both sides ..
    if ((before < mn) || (after < mn)) return {false, 0}; // can't walk mininum on both
    rem -= 2 * mn;  // walk minimum on both
    rem -= min(after, mx) - mn;
    rem = max(0, rem);
    if ((mn+rem) > min(before, mx)) return {false, 0};
    return {true, mn + rem};
  };

  int l = 1, r = 1;
  int sm = 0;

  while (l <= n) {
    auto sol = is_solution(sm, a[l]-a[l-1], a[r+1]-a[r]);
    if (sol.first) {
      cout << a[l] - sol.second << "\n";
      break;
    }

    int nxt = a[r+1] - a[r];
    if ((r < n) && (mn <= nxt && nxt <= mx) && ((sm + nxt) <= m)) {
      sm += nxt;
      r++;
    } else {
      if ((l+1) <= r) {
        sm -= (a[l+1] - a[l]);
      }
      l++;
      r = max(l, r);
    }
  }

  return 0;
}
