#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1 << 20;

int ways[MAXN][3];

int tree[MAXN << 1][4];

inline int mult(int64 a, int64 b) {
  return (a * b)%MOD;
}

void build(int node, int lo, int hi) {
  if (lo == hi) {
    tree[node][0] = ways[lo][1];
    tree[node][1] = 1;
    tree[node][2] = 1;
    tree[node][3] = 0;
  } else {
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    int mid = (lo + hi) >> 1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);

    int cross = mult(ways[mid][2], ways[mid+1][0]) + mult(ways[mid][1], ways[mid+1][1]);
    if (cross >= MOD) cross -= MOD;

    tree[node][0] = mult(tree[ls][1], mult(tree[rs][2], cross));

    int len = hi - lo + 1;
    int lenl = mid-lo+1;
    int lenr = hi-mid;

    if (lenr > 2) {
      tree[node][1] = mult(tree[ls][1], mult(tree[rs][3], cross));
    } else if (lenr == 2) {
      tree[node][1] = mult(tree[ls][1], cross);
    } else {
      tree[node][1] = tree[ls][0];
    }

    if (lenl > 2) {
      tree[node][2] = mult(tree[ls][3], mult(tree[rs][2], cross));
    } else if (lenl == 2) {
      tree[node][2] = mult(tree[rs][2], cross);
    } else {
      tree[node][2] = tree[rs][0];
    }

    if (len < 3) {
      tree[node][3] = 0;
    } else if (len == 3) {
      tree[node][3] = ways[mid][1];
    } else {
      if (lenl == 1) {
        tree[node][3] = tree[rs][1];
      } else if (lenr == 1) {
        tree[node][3] = tree[ls][2];
      } else if (lenl == 2 && lenr == 2) {
        tree[node][3] = cross;
      } else if (lenl == 2) {
        tree[node][3] = mult(tree[rs][3], cross);
      } else if (lenr == 2) {
        tree[node][3] = mult(tree[ls][3], cross);
      } else {
        tree[node][3] = mult(tree[ls][3], mult(tree[rs][3], cross));
      }
    }

  }
}

int changed;
void update(int node, int lo, int hi) {
  if (lo == hi) {
    tree[node][0] = ways[lo][1];
  } else {
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    int mid = (lo + hi) >> 1;
    if (changed <= mid) update(ls, lo, mid);
    if (changed > mid) update(rs, mid+1, hi);

    int cross = mult(ways[mid][2], ways[mid+1][0]) + mult(ways[mid][1], ways[mid+1][1]);
    if (cross >= MOD) cross -= MOD;

    tree[node][0] = mult(tree[ls][1], mult(tree[rs][2], cross));

    int len = hi - lo + 1;
    int lenl = mid-lo+1;
    int lenr = hi-mid;

    if (lenr > 2) {
      tree[node][1] = mult(tree[ls][1], mult(tree[rs][3], cross));
    } else if (lenr == 2) {
      tree[node][1] = mult(tree[ls][1], cross);
    } else {
      tree[node][1] = tree[ls][0];
    }

    if (lenl > 2) {
      tree[node][2] = mult(tree[ls][3], mult(tree[rs][2], cross));
    } else if (lenl == 2) {
      tree[node][2] = mult(tree[rs][2], cross);
    } else {
      tree[node][2] = tree[rs][0];
    }

    if (len < 3) {
      tree[node][3] = 0;
    } else if (len == 3) {
      tree[node][3] = ways[mid][1];
    } else {
      if (lenl == 1) {
        tree[node][3] = tree[rs][1];
      } else if (lenr == 1) {
        tree[node][3] = tree[ls][2];
      } else if (lenl == 2 && lenr == 2) {
        tree[node][3] = cross;
      } else if (lenl == 2) {
        tree[node][3] = mult(tree[rs][3], cross);
      } else if (lenr == 2) {
        tree[node][3] = mult(tree[ls][3], cross);
      } else {
        tree[node][3] = mult(tree[ls][3], mult(tree[rs][3], cross));
      }
    }

  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, M;       cin >> N >> M;
    int Wi, AW, BW; cin >> Wi >> AW >> BW;
    int Di, AD, BD; cin >> Di >> AD >> BD;
    int Si, AS, BS; cin >> Si >> AS >> BS;

    for (int i = 1; i <= N; ++i) {
      ways[i][0] = 0; ways[i][1] = 1; ways[i][2] = 0;
    }
    build(0, 1, N);

    int sum = 0;
    for (int i = 0; i < M; ++i) {
      int Zi = max(1, min(N, Wi + Di - 1));
      int idx = Zi - Wi + 1;
      ways[Wi][idx] += Si % MOD;
      if (ways[Wi][idx] >= MOD) ways[Wi][idx] -= MOD;
      changed = Wi;
      update(0, 1, N);
      sum += tree[0][0];
      if (sum >= MOD) sum -= MOD;
      Wi = ((int64(AW) * int64(Wi) + BW) % N) + 1;
      Di = (AD * Di + BD) % 3;
      Si = ((int64(AS) * int64(Si) + int64(BS)) % 1000000000) + 1;
    }

    cout << "Case #" << tc << ": " << sum << "\n";
  }


  return 0;
}
