#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);


  int N;
  cin >> N;
  while (N--) {
    double a, b, c, starting = 100000.0;
    cin >> a >> b >> c;
    double endsup = ((starting / a) / b) / c;
    int profit = endsup - starting;
    profit = max(0, profit);
    cout << profit << "\n";
  }

  return 0;
}
