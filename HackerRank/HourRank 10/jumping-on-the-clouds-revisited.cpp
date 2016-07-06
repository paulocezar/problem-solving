#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> c(n);
  for (int &v : c) cin >> v;

  int pos = 0, E = 100;
  do {
    pos += k; pos %= n;
    E--;
    if (c[pos]) E -= 2;
  } while (pos != 0);
  cout << E << "\n";

  return 0;
}
