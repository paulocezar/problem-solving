#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct diamond_t {
  int minx, maxx, miny, maxy;
  diamond_t(const vector<pair<int,int>> &pts, bool transform = true) {
    minx = 2e9, maxx = -2e9, miny = 2e9, maxy = -2e9;
    int xx, yy;
    for (auto &p : pts) {
      if (transform) {
        xx = p.first - p.second;
        yy = p.first + p.second;
      } else {
        tie(xx, yy) = p;
      }
      minx = min(minx, xx);
      maxx = max(maxx, xx);
      miny = min(miny, yy);
      maxy = max(maxy, yy);
    }
  }

  int intersect(const diamond_t &d) {
    int x1 = max(minx, d.minx);
    int x2 = min(maxx, d.maxx);
    int y1 = max(miny, d.miny);
    int y2 = min(maxy, d.maxy);
    return max(0, max(0, x2-x1) * max(0, y2-y1) - 1);
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int R, D;
    cin >> R >> D;

    int R2 = R*R;

    diamond_t d1 = diamond_t({{-R,0}, {0, R}, {R, 0}, {0, -R}});

    int64 res = 0;
    for (int x1 = -R; x1 <= R; ++x1) {
      for (int y1 = -R; y1 <= R; ++y1) {
        int dist = x1*x1 + y1*y1;
        if (dist <= R2) {
          int xa = x1 - y1;
          int ya = x1 + y1;
          diamond_t d2 = diamond_t({{xa-D,ya}, {xa, ya+D}, {xa+D, ya}, {xa, ya-D}}, false);
          res += d1.intersect(d2);
        }
      }
    }

    cout << "Caso " << tc << ": " << res << "\n";
  }

  return 0;
}
