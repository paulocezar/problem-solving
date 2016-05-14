#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int c[128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> c[i];

  int cur = 0, ans = 0;
  n--;
  while (cur < n) {
    if (c[cur+2]) cur++;
    else cur += 2;
    ans++;
  }

  cout << ans << "\n";

  return 0;
}
