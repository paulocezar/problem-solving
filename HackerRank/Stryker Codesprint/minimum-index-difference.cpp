#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 11;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  map<int, int> pos;
  for (int i = 0; i < n; ++i) {
    int ax; cin >> ax;
    pos[ax] = i;
  }

  int res = 2e9, vl = 2e9;
  for (int i = 0; i < n; ++i) {
    int ax; cin >> ax;
    int df = abs(i - pos[ax]);
    if (df < res) {
      res = df; vl = ax;
    } else if (df == res && ax < vl) {
      vl = ax;
    }
  }

  cout << vl << "\n";

  return 0;
}
