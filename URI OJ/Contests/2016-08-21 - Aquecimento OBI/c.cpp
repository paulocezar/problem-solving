#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int cnt = 0;
  for (char c : s) {
    if (c == '1') cnt++;
  }
  cout << s;
  cout << char((cnt&1)+ '0') << "\n";

  return 0;
}
