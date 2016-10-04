#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 1e9 + 7;

int64 fpw(int64 a, int64 b) {
  int64 res = 1LL;
  a %= MOD;
  while (b) {
    if (b & 1LL) { res *= a; res %= MOD; }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return res;
}

int64 parse(string &s) {
  vector<int64> mult;

  int n = s.size();

  int64 prev = 0LL, cur = 0LL;
  bool has_prev = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      if (((i+1) < n) && s[i+1] == '*') {
        i++;
        if (has_prev) prev = fpw(prev, cur);
        else prev = cur;
        cur = 0LL;
        has_prev = true;
      } else {
        if (has_prev) cur = fpw(prev, cur);
        mult.push_back(cur);
        cur = 0LL;
        has_prev = false;
      }
    } else {
      cur = 10LL * cur + int64(s[i]-'0');
    }
  }
  if (has_prev) cur = fpw(prev, cur);
  mult.push_back(cur);

  int64 rr = 1LL;
  for (int64 v : mult) {
    v %= MOD;
    rr *= v;
    rr %= MOD;
  }
  return rr;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  regex valid_expr("(\\d+\\*{1,2})*\\d+");

  int t;
  cin >> t; cin.ignore();

  while (t--) {
    string s;
    getline(cin, s);
    if (regex_match(s, valid_expr)) cout << parse(s) << "\n";
    else cout << "Syntax Error\n";
  }

  return 0;
}
