#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool everybody_works(vector<int> &w, int k, int b) {
  int wi = __builtin_popcount(b);
  int worker = w[wi];
  int N = w.size();
  if (wi == N) return true;

  bool all_ok = true;
  bool found_one = false;
  for (int machine = 0; all_ok && (machine < N); ++machine) {
    if (b & (1<<machine)) continue;
    if (k & (1<<(worker*N + machine))) {
      found_one = true;
      all_ok = all_ok && everybody_works(w, k, b | (1<<machine));
    }
  }
  return found_one && all_ok;
}

bool guarantee(int knows, int N) {
  vector<int> workers(N);
  for (int i = 0; i < N; ++i) workers[i] = i;

  do {
    if (!everybody_works(workers, knows, 0)) return false;
  } while (next_permutation(workers.begin(), workers.end()));

  return true;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;
    int knows = 0;
    for (int i = 0; i < N; ++i) {
      string ss; cin >> ss;
      for (int j = 0; j < N; ++j) {
        if (ss[j] == '1') knows |= 1<<(i*N + j);
      }
    }

    int mx = 1<<(N*N);
    int ans = N*N;
    for (int teach = 0; teach < mx; ++teach) {
      if (teach & knows) continue;
      int cur = __builtin_popcount(teach);
      if (cur >= ans) continue;
      if (guarantee(knows | teach, N)) ans = cur;
    }
    cout << "Case #" << tc << ": " << ans << "\n";
  }

  return 0;
}
