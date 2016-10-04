#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

double p[MAXN], x[MAXN], y[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  double res = 0.0;

  priority_queue<double> q;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> y[i];
  }

  for (int i = 0; i < n; ++i) {
    q.push(p[i] * x[i] - (1.0 - p[i])*y[i]);
  }

  while (k--) {
    double cur = q.top(); q.pop();
    if (cur < 0.0) break;
    res += cur;
  }

  cout << fixed << setprecision(2) << res << "\n";

  return 0;
}
