#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int res = 1;
  for (char c : s) {
    if (c == '_') res++;
  }

  cout << res << "\n";

  return 0;
}
