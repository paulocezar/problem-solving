#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1e9 + 9;

vector<int64> colorings[32];

int64 C[1<<17][32];

vector<int> gr[1<<17];

int N, K, F;
int polys[8];

int64 cache[1<<17][8][32];
char cached[1<<17][8][32];

int64 solve(int u, int pt, int pc) {
  int64 &res = cache[u][pt][pc];
  if (cached[u][pt][pc]) return res;
  cached[u][pt][pc] = 1;
  res = 0LL;

  int colors = K - pc;
  for (int type = 0; type < F; ++type) {
    if (type == pt) continue;
    int faces = polys[type];
    int mx_colors = min(colors, faces);
    for (int use = 1; use <= mx_colors; ++use) {
      int64 paintings = (colorings[faces][use-1] * C[colors][use])%mod;
      for (int &v : gr[u]) {
        paintings *= solve(v, type, use);
        paintings %= mod;
      }
      res += paintings;
      res %= mod;
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  colorings[4] = {1, 3, 3, 2};
  colorings[6] = {1, 8, 30, 68, 75, 30};
  colorings[8] = {1, 21, 267, 1718, 5250, 7980, 5880, 1680};
  colorings[12] = {
    1LL,
    94LL,
    8814LL,
    245008LL,
    2759250LL,
    15884004LL,
    52701264LL,
    106866144LL,
    134719200LL,
    103118400LL,
    43908480LL,
    7983360LL
  };
  colorings[20] = {
    1LL,
    17822LL,
    58076586LL,
    93064446LL,
    413485268LL,
    950452260LL,
    538866086LL,
    665139934LL,
    785581076LL,
    442181785LL,
    107114120LL,
    816730280LL,
    865226159LL,
    423463876LL,
    240865690LL,
    492572685LL,
    719193092LL,
    567858965LL,
    161082671LL,
    438008706LL
  };

  cin >> N >> K >> F;
  for (int i = 0; i < F; ++i) cin >> polys[i];

  for (int i = 2; i <= N; ++i) {
    int pi; cin >> pi;
    gr[pi].push_back(i);
  }

  C[0][0] = 1LL;
  for (int i = 1; i <= K; ++i) {
    C[i][0] = 1LL;
    int lim = min(i, 20);
    if (i <= lim) C[i][i] = 1LL;
    else lim++;
    for (int j = 1; j < lim; ++j) {
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
  }

  cout << solve(1, F, 0) << "\n";

  return 0;
}
