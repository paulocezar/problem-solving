#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

const int MAXV = 1 << 18;
const int MAXE = 1 << 22;

int grid[MAXN], rm[MAXN], cm[MAXN];

int last_edge[MAXV], cur_edge[MAXV], dist[MAXV];
int prev_edge[MAXE], cap[MAXE], flow[MAXE], adj[MAXE];
int nedges;

void d_init() {
    nedges = 0;
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
        while((flow = d_augmenting(source, sink, 0x3f3f3f3f)))
            ret += flow;
    }

    return ret;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int p;
  cin >> p;
  while (p--) {
    int r, c, n, m;
    cin >> r >> c >> n >> m;

    auto idx = [&c](int i, int j) -> int {
      return i*c + j;
    };

    int cells = r * c;
    for (int i = 0; i < cells; ++i) grid[i] = 0;

    while (n--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      grid[idx(x1, y1)]++;
      x2++, y2++;
      if (y2 < c) grid[idx(x1,y2)]--;
      if (x2 < r) grid[idx(x2,y1)]--;
      if (x2 < r && y2 < c) grid[idx(x2,y2)]++;
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int acm = 0;
        if (i) acm += grid[idx(i-1,j)];
        if (j) acm += grid[idx(i,j-1)];
        if (i && j) acm -= grid[idx(i-1,j-1)];
        grid[idx(i,j)] += acm;
      }
    }

    int R = 0, C = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (j == 0 || ((grid[idx(i,j)] >= m) && (grid[idx(i,j-1)] < m))) R++;
        rm[idx(i,j)] = R;
      }
    }

    for (int j = 0; j < c; ++j) {
      for (int i = 0; i < r; ++i) {
        if (i == 0 || ((grid[idx(i,j)] >= m) && (grid[idx(i-1,j)] < m))) C++;
        cm[idx(i, j)] = C;
      }
    }

    d_init();
    int src = 0, sink = R + C + 1;
    for (int i = 0; i <= sink; ++i) last_edge[i] = -1;

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (grid[idx(i,j)] >= m) {
          d_edge(rm[idx(i,j)], R + cm[idx(i,j)], 1);
        }
      }
    }

    for (int i = 1; i <= R; ++i) d_edge(src, i, 1);
    for (int i = 1; i <= C; ++i) d_edge(R+i, sink, 1);

    cout << dinic(src, sink) << "\n";

  }

  return 0;
}
