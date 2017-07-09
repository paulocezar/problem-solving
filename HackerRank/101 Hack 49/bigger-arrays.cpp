#include <bits/stdc++.h>

using namespace std;

const int LGMN = 17;
const int MAXN = 1 << LGMN;
const int MOD = 1'000'000'007;

int A[MAXN];
int lazy[1 << (LGMN + 1)];
int64_t m1[1 << (LGMN + 1)];
int64_t m2[1 << (LGMN + 1)];

int fpw(int64_t a, int b) {
  int64_t r = 1LL;
  while (b > 0) {
    if (b & 1) {
      r *= a; r %= MOD;
    }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return r;
}

void build(int node, int lo, int hi) {
  lazy[node] = 0;
  if (lo == hi) {
    m1[node] = A[lo];
    m2[node] = A[lo] - 1;
  } else {
    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);
    m1[node] = (m1[ls] * m1[rs]) % MOD;
    m2[node] = (m2[ls] * m2[rs]) % MOD;
  }
}

void push(int node, int lo, int hi) {
  if (!lazy[node]) return;
  m1[node] = fpw(lazy[node], hi-lo+1);
  m2[node] = fpw(lazy[node]-1, hi-lo+1);
  if (lo != hi) {
    lazy[(node << 1) + 1] = lazy[node];
    lazy[(node << 1) + 2] = lazy[node];
  }
  lazy[node] = 0;
}

int l, r, x;
void put(int node, int lo, int hi) {
  push(node, lo, hi);
  if (hi < l || lo > r) return;

  if (l <= lo && hi <= r) {
    lazy[node] = x;
    push(node, lo, hi);
  } else {
    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    put(ls, lo, mid);
    put(rs, mid+1, hi);
    m1[node] = (m1[ls] * m1[rs]) % MOD;
    m2[node] = (m2[ls] * m2[rs]) % MOD;
  }
}

pair<int64_t, int64_t> get(int node, int lo, int hi) {
  push(node, lo, hi);
  if (hi < l || lo > r) return {1LL, 1LL};
  if (l <= lo && hi <= r) {
    return {m1[node], m2[node]};
  }
  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  auto ll = get(ls, lo, mid);
  auto rr = get(rs, mid+1, hi);
  ll.first *= rr.first; ll.first %= MOD;
  ll.second *= rr.second; ll.second %= MOD;
  return ll;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }

  build(0, 1, n);

  int t;
  int64_t m1, m2;
  while (q--) {
    cin >> t >> l >> r;
    if (t == 1) {
      cin >> x;
      put(0, 1, n);
    } else {
      tie(m1, m2) = get(0, 1, n);
      cout << (m1 - m2 + MOD) % MOD << "\n";
    }
  }

  return 0;
}
