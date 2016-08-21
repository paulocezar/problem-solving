#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<10;
const int MAXC = 1<<7;
const int INF = 1e9;

vector< pair<int,int> > gr[MAXN];

int dp[MAXN][MAXC];
int p[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    gr[i].clear();
  }

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    gr[u].push_back(make_pair(v, c));
    gr[v].push_back(make_pair(u, c));
  }

  int q;
  cin >> q;
  while (q--) {
    int from, to, cap;
    cin >> cap >> from >> to;
    for (int i = 0; i < n; ++i) for (int j = 0; j <= cap; ++j) {
      dp[i][j] = INF;
    }

    dp[from][0] = 0;
    priority_queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(from, 0)));

    while(!q.empty()) {
      int cost = -q.top().first;
      from = q.top().second.first;
      int left = q.top().second.second;
      q.pop();

      if (cost > dp[from][left]) continue;
      if (from == to) break;

      if (left < cap && dp[from][left+1] > dp[from][left]+p[from]) {
        dp[from][left+1] = dp[from][left]+p[from];
        q.push(make_pair( -dp[from][left+1], make_pair(from, left+1)));
      }

      for (int i = 0, sz = gr[from].size(); i < sz; ++i) {
        int w = gr[from][i].second;
        int v = gr[from][i].first;
        if (left >= w && dp[v][left-w] > dp[from][left]) {
          dp[v][left-w] = dp[from][left];
          q.push(make_pair( -dp[v][left-w], make_pair(v, left-w)));
        }
      }
    }

    int ans = INF;
    for (int i = 0; i <= cap; ++i) ans = min(ans, dp[to][i]);
    if (ans == INF) cout << "IMPOSSIVEL\n";
    else cout << ans << "\n";
  }

  return 0;
}
