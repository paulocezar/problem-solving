#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  cout << abs(x-(1<<n)+1) << "\n";


  return 0;
}
