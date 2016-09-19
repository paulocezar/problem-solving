#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

int p[1<<19];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int m;
  cin >> m;

  int N = s.size();


  p[0] = p[1] = 0;

  for (int i = 2; i <= N; ++i) {
    int j = p[i-1];
    while (s[i-1] != s[j]) {
      if (j == 0) { j = -1; break; }
      j = p[j];
    }
    p[i] = ++j;
  }

  int root = N / (N-p[N]);
  if (root * (N-p[N]) != N) root = 1;
  int len = N / root;
  int res = m / len;
  res %= mod;
  cout << res << "\n";

  return 0;
}
