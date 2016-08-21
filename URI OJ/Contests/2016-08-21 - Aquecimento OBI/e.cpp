#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int A, P;
  cin >> A >> P;

  int ans = 0;
  for (int i = 0; i < A; ++i) {
    int Ni; cin >> Ni;
    int cur = 0;
    int laps = 1;
    for (int j = 0; j < Ni; ++j) {
      int pi; cin >> pi;
      if (pi < cur) {
        if ((pi != 0) || ((j+1) < Ni)) laps++;
      }
      cur = pi;
    }
    ans = max(ans, laps);
  }
  cout << ans << "\n";

  return 0;
}
