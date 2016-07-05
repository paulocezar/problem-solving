#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int C[64], mx[1<<17], cnt[1<<17];
int64 gr[64];



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  int64 all = (1LL<<N) - 1LL;
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
    gr[i] = all;
  }

  while (M--) {
    int u, v;
    cin >> u >> v; u--, v--;
    gr[u] &= (all ^ (1LL<<v));
    gr[v] &= (all ^ (1LL<<u));
  }

  int N1 = N >> 1;
  int N2 = N - N1;

  int lmt = 1<<N1;

  for (int mask = 0; mask < lmt; ++mask) {
    int clique_sum = 0;
    for (int i = 0; i < N1; ++i) {
      if (mask & (1<<i)) {
        if ((gr[i] & mask) != mask) {
          clique_sum = -1;
          break;
        }
        clique_sum += C[i];
      }
    }
    mx[mask] = clique_sum, cnt[mask] = 1;
  }

  for (int mask = lmt-1; mask > 0; --mask) {
    for (int smask = (mask-1)&mask; smask > 0; smask=(smask-1)&mask) {
      if (mx[smask] > mx[mask]) {
        mx[mask] = mx[smask];
        cnt[mask] = 1;
      } else if (mx[smask] == mx[mask]) {
        cnt[mask]++;
      }
    }
  }

  int res = mx[lmt-1];
  int64 rcnt = cnt[lmt-1];

  if (N1 > 0) {
    if (res < 0) {
      res = 0;
      rcnt = 1;
    } else if (res == 0) {
      rcnt++;
    }
  }

  lmt = 1<<N2;
  int64 FH = (1LL<<N1) - 1LL;

  for (int mask = 1; mask < lmt; ++mask) {
    int clique_sum = 0;
    int64 clique_ng = all;

    for (int i = 0; i < N2; ++i) {
      if (mask & (1<<i)) {
        if (((gr[N1+i]>>N1) & mask) != mask) {
          clique_sum = -1;
          break;
        }
        clique_ng &= gr[N1+i];
        clique_sum += C[N1+i];
      }
    }

    if (clique_sum >= 0) {
      if (clique_sum > res) {
        res = clique_sum;
        rcnt = 1;
      } else if (clique_sum == res) {
        rcnt++;
      }

      clique_ng &= FH;
      if (clique_ng && (mx[clique_ng] >= 0)) {
        int cur = clique_sum + mx[clique_ng];
        if (cur > res) {
          res = cur;
          rcnt = cnt[clique_ng];
        } else if (cur == res) {
          rcnt += cnt[clique_ng];
        }
      }
    }
  }

  cout << res << " " << rcnt << "\n";

  return 0;
}
