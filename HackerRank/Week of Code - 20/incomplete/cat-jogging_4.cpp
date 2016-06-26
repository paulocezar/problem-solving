#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char popcnt[65536];
uint64 shifted[64];
uint64 gr[783][50000];
vector<int> non_empty[783];

inline int popcount(uint64 val) {
  return popcnt[val&65535ULL] +
         popcnt[(val>>16)&65535ULL] +
         popcnt[(val>>32)&65535ULL] +
         popcnt[(val>>48)&65535ULL];
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  for (int i = 0; i < 64; ++i) shifted[i] = 1ULL<<i;
  for (int i = 1; i < 65536; ++i) popcnt[i] = popcnt[i>>1] + (i&1);

  int N, M, u, v;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    cin >> u >> v; u--, v--;
    gr[v>>6][u] |= shifted[v&63];
    gr[u>>6][v] |= shifted[u&63];
  }

  int max_buckets = (N+63) / 64;
  for (int bucket = 0; bucket < max_buckets; ++bucket) {
    for (int i = 0; i < N; ++i) {
      if (popcount(gr[bucket][i])) non_empty[bucket].push_back(i);
    }
  }

  unordered_map<int64, int> intersection;

  for (int bucket = 0; bucket < max_buckets; ++bucket) {
    int sz = non_empty[bucket].size();
    for (int i = 0; i < sz; ++i) {
      u = non_empty[bucket][i];
      for (int j = i+1; j < sz; ++j) {
        v = non_empty[bucket][j];
        int cnt = popcount(gr[bucket][u] & gr[bucket][v]);
        if (cnt) intersection[(int64(u)<<17) | int64(v)] += cnt;
      }
    }
  }

  int64 res = 0LL;

  for (auto &intr : intersection) {
    int64 cnt = intr.second;
    res += (cnt * (cnt-1LL)) / 2LL;
  }

  res /= 2LL;
  cout << res << "\n";

  return 0;
}
