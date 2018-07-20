#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  int64_t skip = (1LL * k * (k-1)) / 2;
  int64_t first = 2*skip + 1;
  cout << k * (first + k-1) << "\n";


  return 0;
}
