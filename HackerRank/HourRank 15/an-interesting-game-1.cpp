#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
int a[MAXN], mx[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i) mx[i] = max(mx[i-1], a[i]);
      else mx[i] = a[i];
    }

    int cur = 0;
    while (n) {
      int turn_mx = mx[n-1];
      while (a[n-1] != turn_mx) {
        n--;
      }
      n--;
      cur = 1 - cur;
    }

    cout << (cur ? "BOB\n" : "ANDY\n");
  }

  return 0;
}
