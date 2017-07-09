#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string a, b;

  cin >> n;
  cin >> a >> b;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    if (a[i] != '.') res++;
  }
  cout << res << "\n";

  return 0;
}
