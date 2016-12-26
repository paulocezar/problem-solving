#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<int64> a(5);
  int64 all = 0LL;
  for (int64 &v : a) {
    cin >> v;
    all += v;
  }
  sort(a.begin(), a.end());

  cout << all-a[4] << " " << all-a[0] << "\n";

  return 0;
}
