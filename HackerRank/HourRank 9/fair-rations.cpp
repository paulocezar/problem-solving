#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> b(N);

  for (int &v : b) { cin >> v; v &= 1; }

  int res = 0;
  for (int i = 1; i < N; ++i) {
    if (b[i-1]) {
      res += 2;
      b[i] = 1-b[i];
      b[i-1] = 1-b[i-1];
    }
  }

  if (b[N-2] == b[N-1]) cout << res << "\n";
  else cout << "NO\n";

  return 0;
}
