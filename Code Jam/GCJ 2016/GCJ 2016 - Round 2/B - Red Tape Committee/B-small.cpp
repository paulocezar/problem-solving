#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
double p[128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T, K;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cin >> N >> K;

    for (int i  = 0; i < N; ++i) cin >> p[i];

    int mx = 1<<N;
    int K2 = K/2;
    double ans = 0.0;
    for (int mask = 0; mask < mx; ++mask) {
      if (__builtin_popcount(mask) == K) {
        double cur = 0.0;
        for (int sm = mask; sm > 0; sm = (sm-1) & mask) {
          if (__builtin_popcount(sm) == K2) {
            double cc = 1.0;

            for (int i = 0; i < N; ++i) {
              if (mask & (1<<i)) {
                cc *= ((sm & (1<<i)) ? p[i] : (1.0 - p[i]));
              }
            }

            cur += cc;
          }
        }
        ans = max(ans, cur);
      }
    }
    cout << fixed << setprecision(13);
    cout << "Case #" << tc << ": " << ans << "\n";
  }

  return 0;
}
