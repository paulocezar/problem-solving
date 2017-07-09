#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int k, b, m;
  cin >> k >> b >> m;

  int msd = 1;
  int cur = 0;

  for (int i = 0; i < k; ++i) {
    if ((i+1) < k) { msd *= b; msd %= m; }
    cur = cur*b + int(s[i]-'0'); cur %= m;
  }

  int64_t res = cur;
  for (auto i = k; i < s.size(); ++i) {
    cur = ((cur - (msd*int(s[i-k]-'0'))%m)%m + m)%m;
    cur = cur*b + int(s[i]-'0'); cur %= m;
    res += cur;
  }

  cout << res << "\n";

  return 0;
}
