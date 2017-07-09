#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;

    int wrong = 0, wrong_ones = 0;
    int extra = 0;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if ((x&1) == (i&1)) {
        extra += max(0, x - (2 - (i&1)));
        extra = min(extra, 100000);
      } else {
        if (x == 1) wrong_ones++;
        else {
          wrong++;
          extra += max(0, (x - 1) - (2 - (i & 1)));
          extra = min(extra, 100000);
        }
      }
    }
    int res = 0;
    int fix = min(wrong, wrong_ones);
    res += fix;

    wrong -= fix;
    wrong_ones -= fix;

    if (wrong_ones) {
      if (wrong_ones & 1) res = -1;
      else if (extra < wrong_ones) {
        res = -1;
      } else res += wrong_ones;
    } else if (wrong) {
      if (wrong & 1) {
        res = -1;
      } else {
        res += wrong / 2;
      }
    }

    cout << res << "\n";
  }

  return 0;
}
