#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N; cin >> N;

    vector<int> w(N);
    for (int &v : w) cin >> v;

    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    int res = 0;
    for (int i = 0; i < N; ++i) {

      int need = 1;
      while (w[i]*need < 50) need++;

      int rem = N - i;
      if (need > rem) break;
      res++;
      N = N - need + 1;
    }

    cout << "Case #" << tc << ": " << res << "\n";
  }


  return 0;
}
