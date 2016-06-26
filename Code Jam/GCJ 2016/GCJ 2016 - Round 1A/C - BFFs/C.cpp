#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
vector<int> bff;
vector<int> rev[1024];

int depth[1024];

int solve(int cur) {
  int ret = 0;

  int &ngb = bff[cur];
  int &ngbd = depth[ngb];

  if (ngbd) {
    ret = depth[cur] - ngbd + 1;
  } else {
    ngbd = depth[cur] + 1;
    ret = solve(ngb);
    ngbd = 0;
  }

  return ret;
}

void doit(int cur, int &mx) {

  if (depth[cur] > mx) mx = depth[cur];

  for (auto &v : rev[cur]) {
    if (v == bff[cur]) continue;
    depth[v] = depth[cur] + 1;
    doit(v, mx);
    depth[v] = 0;
  }

}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {

    cin >> N;
    bff.resize(N);

    for (int i = 0; i < N; ++i) rev[i].clear();

    for (int i = 0; i < N; ++i) {
      int v; cin >> v; v--;
      bff[i] = v;
      rev[v].push_back(i);
    }

    int res = 0;

    for (int i = 0; i < N; ++i) {
      depth[i] = 1;
      res = max(res, solve(i));
      depth[i] = 0;
    }

    int mx2 = 0;
    for (int i = 0; i < N; ++i) {
      if (bff[bff[i]] == i) {
        int bg = 0, bg2 = 0;
        doit(i, bg);
        doit(bff[i], bg2);
        mx2 +=  bg + bg2 + 2;
      }
    }
    res = max(res, mx2 / 2);

    cout << "Case #" << tc << ": " << res << "\n";

  }

  return 0;
}
