#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = -1;

    bool ok = true;
    for (int i = 0; ok && i < n; ++i) {
      if (a[i] != i && a[i+1] == i && abs(a[i+1]-a[i]) == 1)
        swap(a[i], a[i+1]);

      ok = ok && (a[i] == i);
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";

  }

  return 0;
}
