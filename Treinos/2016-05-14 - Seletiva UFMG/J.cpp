#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  if (A < B) swap(A, B);

  int res = 0;
  while (A != B) {
    int cur = (A / (B+1)) * (B+1);
    res += cur;
    A -= cur;
    swap(A,B);
  }
  cout << res << "\n";

  return 0;
}
