#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int i = 0;
  uint64 n = 0ULL;
  while (isdigit(s[i])) {
    n = 10ULL*n + uint64(s[i]-'0');
    i++;
  }

  uint64 res = 1ULL;
  if (n & 1ULL) {
    uint64 full = 2ULL * (n / 4ULL);
    res += 2ULL * full;
    res += full * 6ULL;
  } else {
    uint64 full = (2ULL * ((n - 1ULL) / 4ULL)) + 1ULL;
    res += 2ULL * full - 1ULL;
    res += full * 6ULL;
  }

  string ord = "fedabc";
  i = 0;
  while (ord[i] != s.back()) { i++; res++; }

  cout << res << "\n";

  return 0;
}
