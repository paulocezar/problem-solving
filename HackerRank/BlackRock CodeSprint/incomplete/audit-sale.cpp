#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct security_t {
  int64 P, C;
  bool operator < (const security_t &s) const {
    if ((P*C) != (s.P*s.C)) return (P*C) > (s.P * s.C);
    if (P != s.P) return P < s.P;
    return C < s.C;
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  vector<security_t> security(N);

  for (auto &s : security) {
    cin >> s.P >> s.C;
  }

  sort(security.begin(), security.end());

  int64 ans = 0LL;
  priority_queue<pair<int64, int>> sell_set_increment;

  for (int i = 0; i < M; ++i) {
    int64 cur = security[i].P * security[i].C;
    int64 inc = (security[i].P * 100LL) - cur;
    ans += cur;
    sell_set_increment.push(make_pair(inc, i));
  }

  priority_queue<int64> candidates;
  for (int i = M; i < N; ++i) candidates.push(security[i].P);

  while (K--) {

    int64 inc1 = -sell_set_increment.top().first;
    int ii = -sell_set_increment.top().second; sell_set_increment.pop();

    int64 inc2 = candidates.empty() ? 0LL : ((100LL * candidates.top()) - (security[ii].P * security[ii].C));

    if (inc1 >= inc2) {
      ans += inc1;
    } else {
      ans += inc2;
      candidates.pop();
      candidates.push(security[ii].P);
    }
  }

  cout << ans << "\n";

  return 0;
}
