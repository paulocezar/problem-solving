#include <bits/stdc++.h>

using namespace std;

void keep_unique(vector<int>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

const int MAXV = 2002;
const int MAXE = 500000;

int last_edge[MAXV], cur_edge[MAXV], dist[MAXV];
int prev_edge[MAXE], cap[MAXE], flow[MAXE], adj[MAXE];
int nedges;

void d_init() {
  nedges = 0;
  memset(last_edge, -1, sizeof last_edge);
}

void d_edge(int v, int w, int capacity, bool r = false) {
  prev_edge[nedges] = last_edge[v];
  cap[nedges] = capacity;
  adj[nedges] = w;
  flow[nedges] = 0;
  last_edge[v] = nedges++;

  if (!r) d_edge(w, v, 0, true);
}

bool d_auxflow(int source, int sink) {
  queue<int> q;
  q.push(source);

  memset(dist, -1, sizeof dist);
  dist[source] = 0;
  memcpy(cur_edge, last_edge, sizeof last_edge);

  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int i = last_edge[v]; i != -1; i = prev_edge[i]) {
      if (cap[i] - flow[i] == 0) continue;
      if (dist[adj[i]] == -1) {
        dist[adj[i]] = dist[v] + 1;
        q.push(adj[i]);

        if (adj[i] == sink) return true;
      }
    }
  }

  return false;
}

int d_augmenting(int v, int sink, int c) {
  if (v == sink) return c;

  for (int& i = cur_edge[v]; i != -1; i = prev_edge[i]) {
    if (cap[i] - flow[i] == 0 || dist[adj[i]] != dist[v] + 1)
      continue;

    int val;
    if (val = d_augmenting(adj[i], sink, min(c, cap[i] - flow[i]))) {
      flow[i] += val;
      flow[i^1] -= val;
      return val;
    }
  }

  return 0;
}

int dinic(int source, int sink) {
  memset(flow, 0, sizeof(flow));
  int ret = 0;
  while (d_auxflow(source, sink)) {
    int flow;
    while (flow = d_augmenting(source, sink, 0x3f3f3f3f))
      ret += flow;
  }

  return ret;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  d_init();
  int source = 0, sink = n+m+1;
  for (int i = 1; i <= n; ++i) d_edge(source, i, 1);
  for (int i = 1; i <= m; ++i) d_edge(n+i, sink, 1);

  int last_flow = 0, lo = 1, hi = 2e9;
  vector<int> course;
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;

    course.resize(k);
    for (int& v : course) cin >> v;
    keep_unique(course);
    hi = min(hi, (int)course.size());
    for (int& v : course) {
      d_edge(i, n+v, 1);
    }
  }

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    for (int i = last_edge[source]; i != -1; i = prev_edge[i]) {
      cap[i] = mid;
    }

    last_flow = dinic(source, sink);
    if (last_flow == n*mid) {
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }

  if (hi > 0) cout << "YES " << hi << "\n";
  else {
    for (int i = last_edge[source]; i != -1; i = prev_edge[i]) {
      cap[i] = 1;
    }

    last_flow = dinic(source, sink);

    cout << "NO " << last_flow << "\n";
  }
  return 0;
}
