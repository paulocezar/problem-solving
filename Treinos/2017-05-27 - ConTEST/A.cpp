#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cnt[1024];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; ++tc) {
    memset(cnt, 0, sizeof(cnt));

    int N, C, V;
    cin >> N >> C >> V;

    for (int i = 0; i < N; ++i) {
      int ai; cin >> ai;
      cnt[ai]++;
    }

    int c1 = 0, c2 = 0;
    for (int n = C; n <= 1000; ++n) c1 += cnt[n];

    for (int n = 1000; n >= 0; --n) {
      if (V <= 0) break;
      if (cnt[n]) c2 = n;
      V -= cnt[n];
    }

    cout << "Caso " << tc << ": " << c1 << " " << c2 << "\n";
  }

  return 0;

}
