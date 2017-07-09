#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

unsigned a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  unsigned forced = 0u;
  unsigned common = 0u;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == (a[i] & -a[i])) forced |= a[i];
    common |= a[i];
  }

  int missing = 0;
  unsigned all = 0u;
  for (int i = 0; i < n; ++i) {
    if (a[i] & forced) continue;
    a[missing++] = a[i];
    common &= a[i];
    all |= a[i];
  }

  n = missing;
  all = min(all, (1u << 25) - 1u);

  unsigned res = all;
  int p2 = __builtin_popcount(res);
  for (unsigned cur = 1; cur <= all; ++cur) {
    if ((cur & all) == cur) {
      int p1 =  __builtin_popcount(cur);
      if ((p1 < p2) || (p1 == p2 && cur < res)) {
        bool ok = true;
        if (!(cur & common)) {
          for (int i = 0; ok && i < n; ++i) {
            ok = a[i] & cur;
          }
        }
        if (ok) res = cur, p2 = p1;
      }
    }
  }

  cout << (res | forced) << "\n";

  return 0;
}
