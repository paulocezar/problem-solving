#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;

vector<pair<int,int>> g[MAXN + 1];
int E[MAXN + 1], mark[MAXN + 1];
int N, C, res;

int dfs(int i, int dist) {
  mark[i] = 1;

  for (auto p: g[i])
    if (mark[p.first] == 0) {
      int r = dfs(p.first, dist+p.second);
      if (r > 0) res += p.second*2;
      E[i] += r;
    }

  if (i != 1) res += (E[i] / C) * dist * 2;
  return E[i] % C;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int A,B,D;

  cin >> N >> C;
  for ( int i = 1; i <= N; i++ ){
    cin >> E[i];
    mark[i] = 0;
  }

  for ( int i = 1; i <= N-1; i++ ){
    cin >> A >> B >> D;
    g[A].emplace_back(B,D);
    g[B].emplace_back(A,D);
  }

  res = 0;
  dfs(1, 0);

  cout << res << endl;

  return 0;
}
