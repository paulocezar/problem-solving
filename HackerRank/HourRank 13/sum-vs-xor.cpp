#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 n;
  cin >> n;

  int bits = 0;
  while (n) {
    if (!(n & 1LL)) bits++;
    n >>= 1;
  }

  cout << (1LL<<bits) << "\n";

  return 0;
}
