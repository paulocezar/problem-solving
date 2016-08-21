#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> mv = {{0,+1}, {+1,0}, {0,-1}, {-1,0}};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, F, C;
  cin >> N >> F >> C;

  auto ok = [&]() { return 0 <= F && F < N && 0 <= C && C < N; };
  auto id = [&]() { return F*N + C + 1; };

  int cnt = 0, seen = 0, total = N*N;
  int cur = 0, step = 1;
  int did = 0, dir = 0;

  while (seen < total) {
    cnt++;

    if (ok()) {
      if (seen) cout << " ";
      cout << id();
      seen++;
    }

    F += mv[dir].first;
    C += mv[dir].second;

    did++;
    if (did == step) {
      dir++; if (dir == 4) dir = 0;
      cur++;
      did = 0;
      if (cur == 2) {
        cur = 0;
        step++;
      }
    }
  }
  cout << "\n" << cnt << "\n";

  return 0;
}
