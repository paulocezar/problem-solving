#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {

    vector<pair<int,int>> pts(3);
    for (auto &p : pts) {
      cin >> p.first >> p.second;
    }

    int64 x1, y1, x2, y2;
    tie(x1, y1) = make_pair(pts[0].first - pts[2].first, pts[0].second - pts[2].second);
    tie(x2, y2) = make_pair(pts[1].first - pts[2].first, pts[1].second - pts[2].second);
    int64 area = x1*y2 - y1*x2;

    cout << "Caso " << tc << ": ";
    if (area > 0) {
      cout << "anti-horario";
    } else if (area < 0) {
      cout << "horario";
    } else {
      cout << "indeterminado";
    }
    cout << "\n";

  }

  return 0;
}
