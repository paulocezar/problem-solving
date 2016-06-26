#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;

    vector<vector<int>> data(2*N - 1, vector<int>(N));
    map<int, int> cnt;
    for (auto &info : data) {
      for (auto &v : info) {
        cin >> v;
        cnt[v]++;
      }
    }

    vector<int> res;
    for (auto &v : cnt) if (v.second & 1) res.push_back(v.first);
    sort(res.begin(), res.end());

    cout << "Case #" << tc << ":";
    for (auto &v : res) cout << " " << v;
    cout << "\n";
  }

  return 0;
}
