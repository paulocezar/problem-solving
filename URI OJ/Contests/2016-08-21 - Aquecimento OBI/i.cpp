#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<14;

vector<pair<int,int>> gr[MAXN];

int comp[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    gr[u].emplace_back(v, c);
    gr[v].emplace_back(u, c);
  }

  int cur_comp = 0, best_num = 0, best_den = 1, idx = -1;
  for (int i = 1; i <= n; ++i) {
    if (!comp[i]) {
      cur_comp++;
      queue<int> q;
      q.push(i);
      comp[i] = cur_comp;

      int largest = 0;
      int sum = 0;
      int paths = 0;

      while (!q.empty()) {
        int u = q.front(); q.pop();
        largest = max(largest, u);

        for (auto &w : gr[u]) {
          if (w.first > u) { paths++; sum += w.second; }
          if (!comp[w.first]) {
            comp[w.first] = cur_comp;
            q.push(w.first);
          }
        }
      }

      if (paths == 0) paths = 1;

      if ((idx == -1) || (best_num*paths > sum*best_den) || ((best_num*paths == sum*best_den) && largest > idx)) {
        best_num = sum; best_den = paths;
        idx = largest;
      }
    }
  }
  cout << idx << "\n";

  return 0;
}
