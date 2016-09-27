#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i == j) continue;
      int cnt = 0;
      for (char c : s) {
        if (c == char('a' + i)) {
          if (cnt & 1) cnt++;
          else { cnt = 0; break; }
        } else if (c == char('a' + j)) {
          if (!(cnt & 1)) cnt++;
          else { cnt = 0; break; }
        }
      }
      res = max(res, cnt);
    }
  }
  if (res == 1) res = 0;
  cout << res << "\n";

  return 0;
}
