#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-9;

int cmp(double a, double b = 0.0){
  if ((a - b) > EPS) return 1;
  if ((b - a) > EPS) return -1;
  return 0;
}


int doit(double W, vector<pair<int,int>> &alm) {
  int ret = 0;
  for (auto &el : alm) {
    double cur = (W*el.first + (100.0-W) * el.second) / 100.0;
    if (cmp(cur, 60.0) >= 0) ret++;
  }
  return ret;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<pair<int,int>> alm(N);
  for (auto &el : alm) cin >> el.first >> el.second;


  int ans = 0;

  for (auto &el : alm) {
    int num = 6000 - (100*el.second);
    int den = (el.first - el.second);
    double w = 0.0;

    if (el.first != el.second) {
      w = double(num) / double(den);
    }
    if ((cmp(w, 0) == -1) || (cmp(w, 100) == 1)) continue;
    ans = max(ans, doit(w, alm));
  }

  cout << ans << "\n";

  return 0;
}
