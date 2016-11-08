#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int a[MAXN], id[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id[i] = i;
  }

  sort(id, id+n, [](int i, int j) -> bool {
    if (a[i] != a[j]) return a[i] < a[j];
    return i < j;
  });

  int res = 0;
  int i = 0;
  while (i < n) {
    while (id[i] != i) {
      swap(id[id[i]], id[i]);
      res++;
    }
    i++;
  }

  sort(id, id+n, [](int i, int j) -> bool {
    if (a[i] != a[j]) return a[i] > a[j];
    return i > j;
  });

  int ax = 0;
  i = 0;
  while (i < n) {
    while (id[i] != i) {
      swap(id[id[i]], id[i]);
      ax++;
    }
    i++;
  }
  res = min(res, ax);

  cout << res << "\n";

  return 0;
}
