#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<10;
const int MAXS = 1<<17;

int el[MAXN];
int dp[2][2*MAXS];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  while (cin >> N && N) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> el[i];
      sum += el[i];
    }
    sum = (sum + 1) / 2;

    for (int i = -sum; i <= sum; ++i) dp[0][MAXS+i] = -1e9;
    dp[0][MAXS] = 0;

    auto ok = [&sum](const int &x) -> bool {
      return -sum <= x && x <= sum;
    };

    int old = 0, cur = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = -sum; j <= sum; ++j) {
        int &res = dp[cur][MAXS + j];
        res = dp[old][MAXS + j];
        if (ok(j+el[i])) res = max(res, el[i] + dp[old][MAXS+j+el[i]]);
        if (ok(j-el[i])) res = max(res, dp[old][MAXS+j-el[i]]);
      }
      old = 1-old;
      cur = 1-cur;
    }
    cout << dp[old][MAXS] << "\n";
  }

  return 0;
}
