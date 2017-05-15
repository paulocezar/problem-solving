#include <bits/stdc++.h>

using namespace std;

template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;

const int MAXN = 1024;
const double PI = acos(-1.0);

struct pancake_t {
  int64_t R, H;
  double r2() { return R * R; }
  int64_t diam() { return R * H; }
  bool operator < (const pancake_t &p) const {
    if (R != p.R) return R < p.R;
    return H < p.H;
  }
};

pancake_t pancakes[MAXN];


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cout << fixed << setprecision(13);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
      cin >> pancakes[i].R >> pancakes[i].H;
    }
    sort(pancakes, pancakes+N);

    min_heap<int64_t> q;
    int64_t d_sum = 0LL;

    for (int i = 0; i < (K-1); ++i) {
      d_sum += pancakes[i].diam();
      q.push(pancakes[i].diam());
    }

    double ans = 0.0;
    for (int i = K-1; i < N; ++i) {
      double cur = PI * pancakes[i].r2() +
                   2.0 * PI * (d_sum + pancakes[i].diam());

      ans = max(ans, cur);

      if (!q.empty() && (q.top() < pancakes[i].diam())) {
        d_sum -= q.top();
        q.pop();
        d_sum += pancakes[i].diam();
        q.push(pancakes[i].diam());
      }
    }

    cout << "Case #" << tc << ": " << ans << "\n";

  }

  return 0;
}
