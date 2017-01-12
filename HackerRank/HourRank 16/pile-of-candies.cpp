#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 128;

int c[MAXN], m1[MAXN], m2[MAXN];


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  m1[0] = m1[n+1] = m2[0] = m2[n+1] = 2e9;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    m1[i] = min(m1[i-1], c[i]);
  }

  for (int i = n; i >= 1; --i) {
    m2[i] = min(m2[i+1], c[i]);
  }

  int res = -1, w = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = min(m1[i-1], min(m2[i+1], 2*c[i]));
    if (cur > res) { res = cur; w = 1; }
    else if (cur == res) w++;
  }

  cout << res << " " << w << "\n";

  return 0;
}
