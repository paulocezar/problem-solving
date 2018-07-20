#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int64_t BIGNUM = numeric_limits<int64_t>::max() - 2e9;
const int MAX_H = 1e9 + 1;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int64_t> bit(N+1, BIGNUM);
  vector<int64_t> p(N, 0);
  vector<int> h(N);

  auto get_min = [&bit] (int idx) {
    int64_t res = BIGNUM; ++idx;
    while (idx > 0) {
      res = min(res, bit[idx]);
      idx -= idx & -idx;
    }
    return res;
  };

  auto add = [&bit,N] (int idx, const int64_t val) {
    ++idx;
    while (idx <= N) {
      bit[idx] = min(bit[idx], val);
      idx += idx & -idx;
    }
  };

  for (int&v : h) cin >> v;
  for (int i = 1; i < N; ++i) cin >> p[i];

  stack<pair<int, int>> active;
  active.push({MAX_H, N});

  for (int i = N-1; i >= 0; --i) {
    while (active.top().first <= h[i]) active.pop();

    const int next_taller = active.top().second;
    const int64_t to_shorter = get_min(next_taller - 1) + h[i];
    const int64_t to_taller = (next_taller == N) ? 0 : (h[next_taller] - h[i] + p[next_taller]);

    p[i] += min(to_shorter, to_taller);

    add(i, p[i] - h[i]);
    active.push({h[i], i});
  }

  cout << p[0] + N << "\n";

  return 0;
}
