#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

vector<int> gr[MAXN];
int a[MAXN], x;

void doit(int u) {
  a[u] = x;
  for (int &v : gr[u]) doit(v);
}

void doit_if(int u) {
  if (a[u] > x) a[u] = x;
  for (int &v : gr[u]) doit_if(v);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  while (m--) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
  }

  int cmd, u;
  while (q--) {
    cin >> cmd;
    switch (cmd) {
      case 1: cin >> u >> x; doit(u); break;
      case 2: cin >> u >> x; doit_if(u); break;
      case 3: cin >> u; cout << a[u] << "\n"; break;
    }
  }

  return 0;
}
