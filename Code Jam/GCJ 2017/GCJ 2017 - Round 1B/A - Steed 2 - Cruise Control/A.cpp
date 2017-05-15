#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 11;
const double EPS = 1e-9;

int SGN(double a) { return (a > EPS) ? 1 : ((a < -EPS) ? -1 : 0); }
int CMP(double a, double b) { return SGN(a-b); }

struct horse_t {
  int K, S;
  bool operator < (const horse_t &o) const {
    return K < o.K;
  }
};

horse_t horse[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(13);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int D, N;
    cin >> D >> N;

    double took = 0.0;
    for (int i = 0; i < N; ++i) {
      cin >> horse[i].K >> horse[i].S;

      double need = double(D - horse[i].K) / double(horse[i].S);
      if (CMP(took, need) < 0) took = need;
    }
    sort(horse, horse+N);

    auto can_do_it = [&](double speed) -> bool {
      double need = double(D) / speed;
      if (CMP(need, took) < 0) return false;

      for (int i = 0; i < N; ++i) {
        if (CMP(horse[i].S, speed) >= 0) continue;
        double meet = double(horse[i].K) / (speed - horse[i].S);
        if (CMP(meet, need) < 0) return false;
      }

      return true;
    };

    double lo = 0.0, hi = double(D) / took;
    int steps = 128;
    while (steps--) {
      double mid = .5 * (lo + hi);

      if (can_do_it(mid)) lo = mid;
      else hi = mid;
    }

    cout << "Case #" << tc << ": " << lo << "\n";

  }

  return 0;
}
