#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  map<int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int ax; cin >> ax;
    cnt[ax]++;
  }
  int res = 0;
  for (auto &v : cnt) res += v.second / 2;
  cout << res <<  "\n";

  return 0;
}
