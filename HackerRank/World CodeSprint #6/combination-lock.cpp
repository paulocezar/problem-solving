#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<int> initial(5), desired(5);

  for (int &v : initial) cin >> v;
  for (int &v : desired) cin >> v;

  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    int dif = abs(initial[i] - desired[i]);
    ans += min(dif, 10 - dif);
  }
  cout << ans << "\n";

  return 0;
}
