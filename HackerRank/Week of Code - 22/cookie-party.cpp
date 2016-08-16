#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 n, m;
  cin >> n >> m;
  int64 md = m % n;
  int64 res = n - md;
  if (res == n) res = 0;
  cout << res << "\n";

  return 0;
}
