#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 17;

int c[MAXN];

vector<pair<int,int>> gr[MAXN];

int64_t res = 0LL;

int64_t red_total, black_total;

pair<int,int> doit(int u, int pa = -1) {
  pair<int,int> r = {0, 0};

  if (c[u]) r.second++;
  else r.first++;

  for (auto &w : gr[u]) {
    if (w.first != pa) {
      auto ax = doit(w.first, u);
      res +=
      (ax.first * (black_total - ax.second) + ax.second * (red_total - ax.first)) * w.second;

      r.first += ax.first;
      r.second += ax.second;
    }
  }

  return r;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  red_total = 0LL, black_total = 0LL;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];

    if (c[i]) black_total++;
    else red_total++;
  }

  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    gr[u].emplace_back(make_pair(v, w));
    gr[v].emplace_back(make_pair(u, w));
  }

  res = 0LL;
  doit(1);
  cout << res << "\n";

  return 0;
}
