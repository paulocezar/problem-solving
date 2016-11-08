#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 7;

vector<pair<int, int>> gr[MAXN];
int d, mask;

bool find(int u, int bt) {
  if (bt == d) return true;

  for (auto &w : gr[u]) {
    if (w.second == ((mask >> bt)&1)) {
      if (find(w.first, bt+1)) return true;
    }
  }

  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m >> d;

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    gr[u].push_back({v, c});
    gr[v].push_back({u, c});
  }

  int lm = (1 << d);
  int res = 0;
  for (mask = 0; mask < lm; ++mask) {
    if (find(1, 0)) {
      res++;
    }
  }
  cout << res <<  '\n';

  return 0;
}
