#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int64>> gr[1<<17];

char status[1<<17];

int S, E;

int64 res, M;
void doit(int u, int64 sum = 0LL) {
  if (u == E) {
    res = max(res, ((sum%M)+M)%M);
    return;
  }
  status[u] = 1;
  for (auto &e : gr[u]) {
    int v = e.first;
    int64 w = e.second;
    if (status[v]) continue;
    doit(v, sum + w);
  }
  status[u] = 0;
}

int seen[512][512], seen_now;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, Q, u, v;
  int64 c;

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> u >> v >> c;
    gr[u].push_back(make_pair(v, c));
    gr[v].push_back(make_pair(u, -c));
  }

  cin >> Q;
  while (Q--) {
    cin >> S >> E >> M;
    seen_now++;
    queue<pair<int,int>> q;
    q.push(make_pair(S, 0));
    seen[S][0] = seen_now;
    while (!q.empty()) {
      u = q.front().first;
      c = q.front().second; q.pop();
      for (auto &e : gr[u]) {
        v = e.first;
        int nc = (((c + e.second)%M)+M)%M;
        if (seen[v][nc] == seen_now) continue;
        seen[v][nc] = seen_now;
        q.push(make_pair(v, nc));
      }
    }
    int res = 0;
    for (int i = M-1; i >= 0; --i) if (seen[E][i] == seen_now) {
      res = i; break;
    }
    cout << res << "\n";
  }

  return 0;
}
