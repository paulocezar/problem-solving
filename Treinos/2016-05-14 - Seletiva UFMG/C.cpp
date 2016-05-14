#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int acm = 0;
  bool ok = true;

  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    acm += x;
    if (acm < 0) ok = false;
  }

  cout << (ok ? "S\n" : "N\n");

  return 0;
}
