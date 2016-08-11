#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, c;
  cin >> n >> m >> c;
  n -= c;
  m -= c;
  int t = n + m + c;
  int64 f = 1LL;
  for (int i = 1; i < t; ++i) f *= int64(i);
  cout << f << "\n";

  return 0;
}
