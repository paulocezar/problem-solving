#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 6;

int X[MAXN], Y[MAXN];

struct square_t {
  int x1, y1, x2, y2;
  square_t(int a, int b, int c, int d) {
    x1 = a, y1 = b;
    x2 = c, y2 = d;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
  }
  bool contains(int x, int y) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, R;
    cin >> N >> R;

    vector<int> xs, ys;
    for (int i = 0; i < N; ++i) {
      cin >> X[i] >> Y[i];
      xs.push_back(X[i]);
      ys.push_back(Y[i]);
    }

    sort(xs.begin(), xs.end()); xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    sort(ys.begin(), ys.end()); ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    int res = 0;
    for (int xa : xs) {
      for (int ya : ys) {
        auto s1 = square_t(xa, ya, xa+R, ya+R);
        for (int xb : xs) {
          for (int yb : ys) {
            auto s2 = square_t(xb, yb, xb+R, yb+R);
            int cur = 0;
            for (int i = 0; i < N; ++i) {
              if (s1.contains(X[i], Y[i]) || s2.contains(X[i], Y[i])) {
                cur++;
              }
            }
            res = max(res, cur);
          }
        }
      }
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }

  return 0;
}
