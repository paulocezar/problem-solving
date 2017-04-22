#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int c;

int d(int a, int b) {
  if (a < b) swap(a, b);
  return min(a-b, c - a + b);
}

struct pr {
  int a, b;
  bool operator < (const pr &p) {
    return d(a, b) > d(p.a, p.b);
  }
};

pr p[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, c;
  cin >> n >> c;

  for (int i = 0; i < n; ++i) {
    cin >> p[i].a >> p[i].b;
  }

  sort(p, p+n);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (d(p[i].a, p[i].b) <= res) break;
    for (int j = i+1; j < n; ++j) {
      int dd = min(d(p[i].a, p[i].b), d(p[j].a, p[j].b));
      if (dd <= res) break;
      dd = min(dd, d(p[i].a, p[j].a));
      dd = min(dd, d(p[i].a, p[j].b));
      dd = min(dd, d(p[i].b, p[j].a));
      dd = min(dd, d(p[i].b, p[j].b));
      res = max(res, dd);
    }
  }
  cout << res << "\n";
  return 0;
}
