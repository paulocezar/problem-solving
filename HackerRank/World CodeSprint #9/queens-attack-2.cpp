#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> dir = {{-1, +1}, { 0, +1}, {+1, +1},
                             {-1,  0},           {+1,  0},
                             {-1, -1}, { 0, -1}, {+1, -1}};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  set<pair<int,int>> obstacles;
  pair<int,int> q;
  cin >> q.first >> q.second;

  while (k--) {
    pair<int,int> o; cin >> o.first >> o.second;
    obstacles.insert(o);
  }

  int res = 0;
  for (auto &d : dir) {
    pair<int,int> cur = {q.first + d.first, q.second + d.second};
    while (1 <= cur.first && cur.first <= n && 1 <= cur.second && cur.second <= n) {
      if (obstacles.count(cur)) break;
      res++;
      cur.first += d.first; cur.second += d.second;
    }
  }
  cout << res << "\n";

  return 0;
}
