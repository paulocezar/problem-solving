#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int A, B, C, D;
  cin >> A >> B >> C >> D;

  bool ok = false;
  if (B == D) {
    ok = A == C;
  } else {
    int j = (C-A) / (B-D);
    ok = (j >= 0) && (j*(B-D) == (C-A));
  }

  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
