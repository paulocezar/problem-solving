#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, x;
  cin >> n >> k >> x;

  int64_t x_last = (x == 1) ? 1 : 0;
  int64_t other_last = 1 - x_last;

  for (int i = 2; i < n; ++i) {
    x_last = (x_last * (k - 1) + other_last * (k - 2)) % MOD;
    swap(x_last, other_last);
  }

  cout << other_last << "\n";

  return 0;
}
