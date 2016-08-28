#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  int64 sum = 0;
  for (int i = 0; i < n; ++i) {
    int64 val;
    cin >> val;
    if (i != k) sum += val;
  }
  sum /= 2;
  int64 b;
  cin >> b;
  b -= sum;
  if (b > 0) cout << b << "\n";
  else cout << "Bon Appetit\n";

  return 0;
}
