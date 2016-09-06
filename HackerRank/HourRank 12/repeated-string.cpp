#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int64 n;
  cin >> n;

  int len = s.size();
  int64 full = n / len;
  int rem = n % len;

  int64 res = 0LL;
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] == 'a') {
      cnt++;
      if (i < rem) res++;
    }
  }

  res += cnt * full;

  cout << res << "\n";

  return 0;
}
