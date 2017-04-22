#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  if (n < k || ((n > 2) && (k == 2))) cout << "-1\n";
  else {
    cout << 2 * n - (k + 1) << "\n";
  }

  return 0;
}
