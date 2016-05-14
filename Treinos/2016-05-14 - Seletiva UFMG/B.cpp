#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N; cin >> N;
  int inv = 0;

  int a, ans = 0;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    if (inv) a = 1-a;
    inv = 0;
    if (a == 0) {
      inv = 1;
      ans++;
    }
  }

  if (inv) ans = -1;
  cout << ans << "\n";

  return 0;
}
