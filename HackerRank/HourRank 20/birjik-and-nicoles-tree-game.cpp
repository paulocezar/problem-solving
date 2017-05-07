#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 19;

vector<int> gr[MAXN];

int query[MAXN];
int queried[MAXN];

int cnt[MAXN];

int doit(int u, int pa = -1) {
  int cur = queried[u];
  for (int v : gr[u]) {
    if (v != pa) cur += doit(v, u);
  }
  cnt[cur]++;
  return cur;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) { cin >> query[i]; queried[query[i]] = 1; cnt[i] = 0; } cnt[k] = 0;
    doit(1);
    for (int i = 0; i <= k; ++i) cout << cnt[i] << " "; cout << "\n";
    for (int i = 0; i < k; ++i) { queried[query[i]] = 0; }
  }

  return 0;
}
