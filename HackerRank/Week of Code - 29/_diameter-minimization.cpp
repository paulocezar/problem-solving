#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1024;

vector<int> gr[MAXN];
int last_seen[MAXN], seen;

int get_diam() {
  queue<int> q;
  last_seen[0] = ++seen;
  q.push(0);
  int u;
  while (!q.empty()) {
    u = q.front(); q.pop();
    for (int v : gr[u]) {
      if (last_seen[v] != seen) {
        q.push(v);
        last_seen[v] = seen;
      }
    }
  }

  last_seen[u] = ++seen;
  q.push(u);
  int dd = 0;
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      u = q.front(); q.pop();
      for (int v : gr[u]) {
        if (last_seen[v] != seen) {
          q.push(v);
          last_seen[v] = seen;
        }
      }
    }
    ++dd;
  }
  return dd - 1;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  random_device rd;
  mt19937 eng(rd());

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    gr[i].clear();
  }

  for (int i = 0; i < n; ++i) {
    gr[i].push_back((i+1)%n);
    gr[i].push_back((i-1+n)%n);
  }

  uniform_int_distribution<int> rnd(0, n-1);

  if (m > 2) {
    int skp = n / 2;
    for (int i = 0; (i + skp) < n; ++i) {
      gr[i].push_back(i + skp);
      gr[i+ skp].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
      while (int(gr[i].size()) < m) {
        int nx = rnd(eng);
        if (gr[nx].size() < m) {
          gr[i].push_back(nx);
          gr[nx].push_back(i);
        }
      }
    }
  }

  cout << get_diam() << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) cout << " ";
      cout << gr[i][j];
    }
    cout << "\n";
  }

  return 0;
}
