#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int lazy[1<<18];
int segt[1<<18];

void build(int node, int lo, int hi) {
  if (lo == hi) {
    segt[node] = lazy[lo];
    lazy[node] = -1;
  } else {
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);
    segt[node] = segt[ls] ^ segt[rs];
    lazy[node] = -1;
  }
}

void push(int node, int len){
  if (-1 == lazy[node]) return;

  if (len > 1) {
    int ls = (node<<1)+1;
    int rs = ls+1;
    lazy[ls] = lazy[node];
    lazy[rs] = lazy[node];
  }

  segt[node] = (len & 1) ? lazy[node] : 0;
  lazy[node] = -1;
}

int from, to, v;
void update(int node, int lo, int hi) {
  if (from <= lo && hi <= to) {
    lazy[node] = v;
    push(node, hi - lo + 1);
  } else {
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;

    push(node, hi-lo+1);

    if (mid >= from) update(ls, lo, mid);
    else push(ls, mid-lo+1);

    if (mid+1 <= to) update(rs, mid+1, hi);
    else push(rs, hi-mid);

    segt[node] = segt[ls] ^ segt[rs];
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) cin >> lazy[i];
  build(0, 0, n-1);

  while (m--) {
    cin >> from >> to >> v; from--, to--;
    update(0, 0, n-1);

    cout << (segt[0] ? "Possivel\n" : "Impossivel\n");
  }

  return 0;
}
