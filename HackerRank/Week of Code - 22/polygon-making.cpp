#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> sides(n);
  int sum = 0;
  for (int &v : sides) { cin >> v; sum += v; }

  int res = 0;
  for (int &v : sides) {
    int cnt = 1 + ((2 * v) / sum);
    res += cnt - 1;
  }
  cout << res << "\n";

  return 0;
}
