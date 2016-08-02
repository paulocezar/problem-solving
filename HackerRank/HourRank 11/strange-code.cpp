#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 t;
  cin >> t;

  int64 len = 3LL;
  int64 acm = 0LL;
  while ((acm+len) < t) {
    acm += len;
    len *= 2LL;
  }
  t -= acm;
  cout << len - t + 1LL << "\n";

  return 0;
}
