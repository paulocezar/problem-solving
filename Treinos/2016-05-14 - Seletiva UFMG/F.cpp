#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MX = 1<<18;

struct segtree {
  int val[MX];
  int N, from, to, put;

  void update(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
      val[node] = put;
    } else {
      int mid = (lo+hi) >> 1;
      int ls = (node<<1) + 1;
      int rs = ls + 1;

      if (val[node]) val[ls] = val[node];
      if (val[node]) val[rs] = val[node];

      if (mid >= from) update(ls, lo, mid);
      if (mid < to) update(rs, mid+1, hi);

      val[node] = 0;
    }
  }

  int retrieve(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
      return val[node];
    } else {
      int mid = (lo+hi) >> 1;
      int ls = (node<<1) + 1;
      int rs = ls + 1;

      if (val[node]) val[ls] = val[node];
      if (val[node]) val[rs] = val[node];

      if (mid >= from) return retrieve(ls, lo, mid);
      return retrieve(rs, mid+1, hi);
    }
  }

  void set(int lo, int hi, int color) {
    from = lo, to = hi, put = color;
    update(0, 1, N);
  }
  int get(int at) {
    from = to = at;
    return retrieve(0, 1, N);
  }
} row, col;

int color[MX];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, Q, A, B;
  cin >> N >> M >> Q;

  row.N = N;
  col.N = M;

  for (int op = 1; op <= Q; ++op) {
    char cmd; cin >> cmd;
    switch (cmd) {
      case 'H': cin >> A >> B >> color[op];
        row.set(A, B, op);
        break;
      case 'V': cin >> A >> B >> color[op];
        col.set(A, B, op);
        break;
      case 'C': cin >> A >> B;
        cout << color[max(row.get(A), col.get(B))] << "\n";
        break;
    }
  }


  return 0;
}
