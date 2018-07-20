#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  auto to_int = [&n](int x, int y) {
    if (x == 0) return y;
    if (y == n) return n + x;
    if (x == n) return 3*n - y;
    return 4*n - x;
  };

  auto min_dist = [&n](int from, int to) {
    int dist = to - from;
    if (dist < 0) dist += 4*n;
    return dist;
  };

  vector<int> sockets(m);

  for (int& v : sockets) {
    int x, y; cin >> x >> y;
    v = to_int(x, y);
  }

  sort(sockets.begin(), sockets.end());

  int res = 2e9;
  for (int i = 0; i < m; ++i) {
    int j = (i+k-1) % m;
    if (i <= j) res = min(res, min_dist(sockets[i], sockets[j]));
    else {
      res = min(res, min_dist(sockets[i], sockets[m-1]) +
                     min_dist(sockets[m-1], sockets[0]) +
                     min_dist(sockets[0], sockets[j]));
    }
  }
  cout << res << "\n";

  return 0;
}
