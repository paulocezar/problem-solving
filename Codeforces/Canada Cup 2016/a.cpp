#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int res = 0;

  int i = 0;
  while (i < n && s[i] == '<') { res++; i++; }
  i = n-1;
  while (i >= 0 && s[i] == '>') { res++; i--; }

  cout << res << "\n";

  return 0;
}
