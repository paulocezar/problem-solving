#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  set<int> U;

  char p = '?';
  int cur = 0;

  for (char c : s) {
    if (c != p) {
      cur = 0;
    }

    p = c;
    cur = cur + int(p-'a'+1);
    U.insert(cur);
  }

  int n;
  cin >> n;
  while (n--) {
    int x; cin >> x;
    if (U.count(x)) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
