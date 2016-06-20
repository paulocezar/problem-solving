#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXV = 500000;
const int MAXE = 2 * MAXV;

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

    if(!r) d_edge(w, v, 0, true);
}

bool d_auxflow(int source, int sink) {
    queue<int> q;
    q.push(source);

    memset(dist, -1, sizeof dist);
    dist[source] = 0;
    memcpy(cur_edge, last_edge, sizeof last_edge);

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int i = last_edge[v]; i != -1; i = prev_edge[i]) {
            if(cap[i] - flow[i] == 0) continue;

            if(dist[adj[i]] == -1) {
                dist[adj[i]] = dist[v] + 1;
                q.push(adj[i]);

                if(adj[i] == sink) return true;
            }
        }
    }

    return false;
}

int d_augmenting(int v, int sink, int c) {
    if(v == sink) return c;

    for(int& i = cur_edge[v]; i != -1; i = prev_edge[i]) {
        if(cap[i] - flow[i] == 0 || dist[adj[i]] != dist[v] + 1)
            continue;

        int val;
        if((val = d_augmenting(adj[i], sink, min(c, cap[i] - flow[i])))) {
            flow[i] += val;
            flow[i^1] -= val;
            return val;
        }
    }

    return 0;
}

int dinic(int source, int sink) {
    int ret = 0;
    while(d_auxflow(source, sink)) {
        int flow;
        while((flow = d_augmenting(source, sink, 2e9)))
            ret += flow;
    }

    return ret;
}

vector<pair<int,int>> gr[MAXV];
int tdist[MAXV], T[MAXV], L[MAXV];

void doit(int u, int pa = -1) {
  for (auto &e : gr[u]) {
    if (e.first == pa) continue;
    tdist[e.first] = tdist[pa] + e.second;
    L[e.first] = L[pa] + 1;
    doit(e.first, u);
    T[e.first] = u;
  }
}

int P[MAXV][20];

void process(int N) {
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; (1 << j) < N; j++)
            P[i][j] = -1;

    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; (1 << j) < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int query(int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

int get_dist(int u, int v) {
  return tdist[u] + tdist[v] - 2 * tdist[query(u, v)];
}

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  d_init();
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    cin >> u >> v >> c; u--, v--;
    gr[u].push_back(make_pair(v,c));
    gr[v].push_back(make_pair(u,c));
  }

  tdist[0] = 0;
  L[0] = 0;
  T[0] = 0;
  doit(0);
  process(n);

  for (int u = 0; u < n; ++u) {
    for (int v = u+1; v < n; ++v) {
      if (nedges >= MAXE) continue;
      int dd = get_dist(u, v);
			d_edge(u, v, dd, true);
      d_edge(v, u, dd, true);
    }
  }

  cout << dinic(0, n-1) << "\n";

  return 0;
}
