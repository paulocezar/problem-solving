#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    set<char> has;
    int res = 0;
    for (char c : s) {
      if (has.insert(c).second) res++;
    }
    cout << res << "\n";
  }


  return 0;
}
