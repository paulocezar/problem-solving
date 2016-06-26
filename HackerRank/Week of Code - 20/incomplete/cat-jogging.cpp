#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char popcnt[65536];
unsigned short shifted[16];
vector<int> non_empty[3125];
unsigned short gr[3125][50000];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  for (int i = 0; i < 16; ++i) shifted[i] = 1<<i;
  for (int i = 1; i < 65536; ++i) popcnt[i] = popcnt[i>>1] + (i&1);

  int N, M, u, v;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    cin >> u >> v; u--, v--;
    gr[v>>4][u] |= shifted[v&15];
    gr[u>>4][v] |= shifted[u&15];
  }

  int max_buckets = (N+15) / 16;
  for (int bucket = 0; bucket < max_buckets; ++bucket) {
    for (int i = 0; i < N; ++i) {
      if (popcnt[gr[bucket][i]]) non_empty[bucket].push_back(i);
    }
  }

  map<int, map<int, int>> intersection;

  for (int bucket = 0; bucket < max_buckets; ++bucket) {
    int sz = non_empty[bucket].size();
    for (int i = 0; i < sz; ++i) {
      u = non_empty[bucket][i];
      for (int j = i+1; j < sz; ++j) {
        v = non_empty[bucket][j];
        intersection[u][v] += popcnt[gr[bucket][u] & gr[bucket][v]];
      }
    }
  }

  int64 res = 0LL;

  for (auto &uu : intersection) {
    for (auto &vv : uu.second) {
      int64 cnt = vv.second;
      res += (cnt * (cnt-1LL)) / 2LL;
    }
  }

  res /= 2LL;
  cout << res << "\n";

  return 0;
}
