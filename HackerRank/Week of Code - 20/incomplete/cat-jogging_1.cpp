#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1<<16];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, u, v;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    sort(gr[i].begin(), gr[i].end());
  }

  int64 res = 0LL;
  for (int i = 1; i <= N; ++i) {
    for (int j = i+1; j <= N; ++j) {
      int64 cnt = 0LL;
      int ii = 0, jj = 0, iz = gr[i].size(), jz = gr[j].size();
      while ((ii < iz) && (jj < jz)) {
        if (gr[i][ii] == gr[j][jj]) {
          cnt++;
          ii++;
          jj++;
        } else if (gr[i][ii] < gr[j][jj]) {
          ii++;
        } else {
          jj++;
        }
      }
      res += (cnt*(cnt-1LL))/2LL;
    }
  }

  res /= 2LL;
  cout << res << "\n";

  return 0;
}
