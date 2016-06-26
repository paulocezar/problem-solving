#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char popcnt[65536];
unsigned short shifted[16];
vector<short> non_empty[50000];
unsigned short gr[50000][3125];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  for (int i = 0; i < 16; ++i) shifted[i] = 1<<i;
  for (int i = 1; i < 65536; ++i) popcnt[i] = popcnt[i>>1] + (i&1);

  int N, M, u, v;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    cin >> u >> v; u--, v--;
    gr[u][v>>4] |= shifted[v&15];
    gr[v][u>>4] |= shifted[u&15];
  }

  int max_blocks = (N+15) / 16;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < max_blocks; ++j) {
      if (popcnt[gr[i][j]]) non_empty[i].push_back(j);
    }
  }

  int64 res = 0LL;
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      int64 cnt = 0LL;
      if (non_empty[i].size() < non_empty[j].size()) {
        for (short &bl : non_empty[i]) { cnt += popcnt[gr[i][bl] & gr[j][bl]]; }
      } else {
        for (short &bl : non_empty[j]) { cnt += popcnt[gr[i][bl] & gr[j][bl]]; }
      }
      res += (cnt*(cnt-1LL))/2LL;
    }
  }

  res /= 2LL;
  cout << res << "\n";

  return 0;
}
