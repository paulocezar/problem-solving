#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10'000'000;
const int BIG = 100 * MAXN;

int R[MAXN], D[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, s, t, g, seed, p;
  cin >> n >> s >> t;
  cin >> R[0] >> g >> seed >> p;

  D[0] = BIG;
  for (int i = 1; i < n; ++i) {
    R[i] = (int64_t(R[i-1]) * g + seed) % p;
    D[i] = BIG;
  }

  D[s] = 0;
  int l = s, r = s;
  int nl = s - R[s], nr = s + R[s];
  int cur_distance = 1;

  while ((r-l+1) < n) {
    int lo = nl, hi = nr;

    while (nl < l) {
      l -= 1;
      int actual_l = ((l%n)+n) % n;
      D[actual_l] = min(D[actual_l], cur_distance);
      lo = min(lo, l - R[actual_l]);
      hi = max(hi, l + R[actual_l]);
    }

    while (r < nr) {
      r += 1;
      int actual_r = r%n;
      D[actual_r] = min(D[actual_r], cur_distance);
      lo = min(lo, r - R[actual_r]);
      hi = max(hi, r + R[actual_r]);
    }

    if (lo == nl && hi == nr) break;
    nl = lo, nr = hi;
    cur_distance++;
  }

  if (D[t] == BIG) D[t] = -1;

  cout << D[t] << "\n";

  return 0;
}
