#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<vector<int>> x(2, vector<int>(3, 0));

  for (auto &v : x) {
    for (auto &a : v) cin >> a;
  }

  vector<int> score(2, 0);
  for (int i = 0; i < 3; ++i) {
    if (x[0][i] > x[1][i]) {
      score[0]++;
    } else if (x[0][i] < x[1][i]) {
      score[1]++;
    }
  }

  cout << score[0] << " " << score[1] << "\n";

  return 0;
}
