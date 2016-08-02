#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1e9 + 7;

inline int64 toint(string &s) {
  int64 res = 0LL;
  for (char &c : s) {
    res = 10LL*res + int64(c-'0');
  }
  return res;
}

inline bool irresponsible(int64 x) {
  int64 x1 = x+1;
  while (x || x1) {
    int a = x%10, b = x1 % 10;
    if ((a+b) >= 10) return true;
    x /= 10LL; x1 /= 10LL;
  }
  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string x; int n;
  cin >> x >> n;
  string ss = "";
  while (n--) ss += x;
  int64 s = toint(ss);

  int64 ans = 0LL;

  while (s >= 1LL) {
    if (irresponsible(s)) ans++;
    s--;
  }

  ans %= mod;
  cout << ans << "\n";



  return 0;
}
