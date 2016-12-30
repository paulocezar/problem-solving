#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  k = 240 - k;
  int res = 0;
  while ((res+1)*5 <= k) {
    res++;
    if (res == n) break;
    k -= res * 5;
  }
  cout << res << "\n";

  return 0;
}
