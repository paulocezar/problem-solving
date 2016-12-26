#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, p;
  cin >> n >> p;

  int a = p / 2;
  p = n - p + 1 - (n & 1);
  int b = p / 2;

  cout << min(a, b) << "\n";

  return 0;
}
