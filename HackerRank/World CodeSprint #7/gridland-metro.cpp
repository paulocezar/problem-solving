#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 n, m; int k;
  cin >> n >> m >> k;

  int64 res = n * m;

  map<int, vector<pair<int, int>>> tracks;
  for (int i = 0; i  < k; ++i) {
    int r, c1, c2;
    cin >> r >> c1 >> c2;
    tracks[r].emplace_back(make_pair(c1, c2));
  }

  for (auto &r : tracks) {
    auto &track = r.second;
    sort(track.begin(), track.end());
    int prev_end = 0;
    for (auto &tr : track) {
      if (tr.first <= prev_end) tr.first = prev_end + 1;
      if (tr.first > tr.second) continue;
      res -= tr.second - tr.first + 1;
      prev_end = tr.second;
    }
  }

  cout << res << "\n";


  return 0;
}
