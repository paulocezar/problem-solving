#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 128;

vector<string> person[MAXN];
vector<string> event[MAXN];
vector<int> gr[MAXN];
bool seen[MAXN];
int m[MAXN], m1[MAXN];

int N;

int dfs(int u) {
  if (u < 0) return 1;
  if (seen[u]) return 0;
  seen[u] = true;
  for (int v : gr[u]) {
    if (dfs(m1[v])) {
      m[u] = v;
      m1[v] = u;
      return 1;
    }
  }
  return 0;
}

int dfsExp(int u) {
  for (int i = 0; i < N; ++i) seen[i] = false;
  return dfs(u);
}

int bipMatch() {
  for (int i = 0; i < N; ++i) m[i] = -1, m1[i] = -1;
  int aug, ans = 0;
  do {
    aug = 0;
    bool first = true;
    for (int i = 0; i < N; ++i) if (m[i] < 0) {
      if (first) aug += dfsExp(i);
      else aug += dfs(i);
      first = false;
    }
    ans += aug;
  } while (aug);
  return ans;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int ax, m;
    cin >> ax >> m;
    person[i].resize(m);
    while (m--) {
      cin >> person[i][m];
    }
    sort(person[i].begin(), person[i].end());
  }

  for (int i = 0; i < N; ++i) {
    int m; cin >> m;
    event[i].resize(m);
    while (m--) {
      cin >> event[i][m];
    }
    sort(event[i].begin(), event[i].end());
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int ii = 0, jj = 0, si = person[i].size(), sj = event[j].size();
      while (ii < si && jj < sj) {
        if (person[i][ii] == event[j][jj]) {
          gr[i].push_back(j);
          break;
        } else if (person[i][ii] < event[j][jj]) {
          ii++;
        } else jj++;
      }
    }
  }

  cout << bipMatch() << "\n";

  return 0;
}
