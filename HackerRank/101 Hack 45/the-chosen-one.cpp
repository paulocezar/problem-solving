#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int64 a[MAXN];
int64 g1[MAXN];
int64 g2[MAXN];

int64 gcd(int64 a, int64 b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    g1[i] = i ? (gcd(g1[i-1], a[i])) : (a[i]);
  }

  if (n == 1) { cout << a[0] + 1 << "\n"; return 0; }

  for (int i = n-2; i >= 0; --i) {
    g2[i] = gcd(g2[i+1], a[i]);
  }

  for (int ex = 0; ex < n; ++ex) {
    int64 gp = ex ? g1[ex-1] : 0LL;
    int64 gn = (ex+1) < n ? g2[ex+1] : 0LL;
    int64 gg = gcd(gp, gn);;
    if (a[ex] % gg) {
      cout << gg << "\n";
      break;
    }
  }


  return 0;
}
