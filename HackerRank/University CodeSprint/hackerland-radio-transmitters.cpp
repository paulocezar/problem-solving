#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int x[MAXN];


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  sort(x, x+n);

  int res = 0, i = 0, j = 0;

  while (i < n) {
    res++;
    while ((j < n) && ((x[j]-x[i]) <= k)) j++;
    i = j-1;
    j = i;
    while ((j < n) && ((x[j]-x[i]) <= k)) j++;
    i = j;
  }

  cout << res << "\n";

  return 0;
}
