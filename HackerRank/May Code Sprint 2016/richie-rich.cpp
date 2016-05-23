#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int i = 0, j = n-1;
  set<int> changed;
  while (i < j) {
    if (s[i] != s[j]) {
      s[i] = s[j] = max(s[i], s[j]);
      changed.insert(i);
      k--;
    }
    i++, j--;
  }

  if (k < 0) {
    cout << "-1\n";
  } else {
    i = 0, j = n-1;
    while (k && (i <= j)) {
      if (s[i] != '9') {
        int cost = 2;
        if (changed.count(i) || (i == j)) cost--;
        if (cost <= k) {
          s[i] = s[j] = '9';
          k -= cost;
        }
      }
      i++, j--;
    }
    cout << s << "\n";
  }

  return 0;
}
