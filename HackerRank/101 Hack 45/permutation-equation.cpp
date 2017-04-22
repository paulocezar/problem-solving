#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 6;

int p[MAXN];



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> p[i];

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      if (p[p[y]] == x) {
        cout << y << "\n";
        break;
      }
    }
  }


  return 0;
}
