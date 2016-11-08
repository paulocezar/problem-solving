#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s, t;
  int k;
  cin >> s >> t >> k;

  int n = s.size(), m = t.size(), pref = 0;
  while (pref < n && pref < m) {
    if (s[pref] == t[pref]) pref++;
    else break;
  }
  int need = n + m - 2 * pref;
  int rem = k - need;

  if ((rem >= 0) && ((rem >= (2 * pref)) || !(rem % 2))) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
