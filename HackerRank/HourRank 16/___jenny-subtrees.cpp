#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 12;

int last_active[MAXN], last_removed[MAXN], deg[MAXN];
int active_now, removed_now, cid;

vector<int> gr[MAXN];
map<vector<int>, int> id;

void find_active(int u, int rem, int pa = -1) {
  last_active[u] = active_now;
  deg[u] = 0;
  if (!rem) return;
  for (int v : gr[u]) if (v != pa) {
    find_active(v, rem-1, u);
    deg[u]++;
    deg[v]++;
  }
}

pair<int,int> find_centers(int n) {
  int cur_n = 0;
  removed_now++;
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (last_active[i] == active_now) {
      cur_n++;
      if (deg[i] == 1) {
        last_removed[i] = removed_now;
        q.push(i);
      }
    }
  }

  int step = 0;
  while (step < (cur_n - 2)) {
    int u = q.front(); q.pop();
    for (int v : gr[u]) if ((last_active[v] == active_now) && (last_removed[v] != removed_now)) {
      deg[v]--;
      if (deg[v] == 1) {
        q.push(v);

        last_removed[v] = removed_now;
      }
    }
    step++;
  }

  pair<int,int> res = make_pair(-1, -1);
  res.first = q.front(); q.pop();
  if (!q.empty()) res.first = q.front();

  return res;
}

int encode(int u, int pa = -1) {
  vector<int> code;
  for (int v : gr[u]) if (v != pa && last_active[v] == active_now) {
    code.push_back(encode(v, u));
  }

  sort(code.begin(), code.end());
  if (!id.count(code)) id[code] = cid++;
  return id[code];
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, r;
  cin >> n >> r;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  if (r == 0) {
    cout << "1\n";
    return 0;
  }

  cid = 1;
  set<pair<int,int>> seen;

  for (int i = 1; i <= n; ++i) {
    active_now++;
    find_active(i, r);
    auto centers = find_centers(n);
    centers.first = encode(centers.first);
    if (centers.second != -1) {
      centers.second = encode(centers.second);
    }
    if (centers.first > centers.second) swap(centers.first, centers.second);
    seen.insert(centers);
  }
  cout << seen.size() << "\n";

  return 0;
}
