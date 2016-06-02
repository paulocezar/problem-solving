#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 H[1<<17];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> H[i];
    sort(H, H+N);
    for (int i = N-2; i >= 0; --i) H[i] += H[i+1];
    H[N] = 0LL;

    int64 ans = 0LL;
    for (int i = 0; i < N; ++i) {
      ans = max(ans, int64(i+1) * H[i]);
    }
    cout << ans << "\n";
  }

  return 0;
}
