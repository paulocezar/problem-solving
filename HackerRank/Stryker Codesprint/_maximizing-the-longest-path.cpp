#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<19;

int L[MAXN], pa[MAXN];
vector<int> gr[MAXN];
int seen[MAXN], seen_now;
bitset<MAXN> inpath;

int doit(int from) {
  queue<int> q;
  pa[from] = from;
  q.push(from); seen[from] = ++seen_now;
  L[from] = 0;
  int u = from;
  while (!q.empty()) {
    u = q.front(); q.pop();
    for (int v : gr[u]) {
      if ((seen[v] == seen_now) || inpath[v]) continue;
      L[v] = L[u] + 1;
      pa[v] = u;
      seen[v] = seen_now;
      q.push(v);
    }
  }
  return u;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, u, v;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int v1 = doit(1);
  int v2 = doit(v1);
  int diam = L[v2];

  vector<int> path;
  while (true) {
    inpath[v2] = 1;
    path.push_back(v2);
    if (pa[v2] == v2) break;
    v2 = pa[v2];
  }

  int res = diam;
  int gr1 = 0;
  for (int& v : path) {
    v = L[doit(v)];
    res = max(res, diam + v);
    if (v >= 1) gr1++;
  }

  int plen = path.size();
  if (gr1 >= 2) {
    for (int sep = 1; sep <= plen; ++sep) {
      for (int i = 0; i+sep < plen; ++i) {
        int lturn = max(diam - sep + 1, sep);
        res = max(res, lturn + path[i] + path[i+sep]);
      }
    }
  }

  cout << res <<  "\n";

  return 0;
}
