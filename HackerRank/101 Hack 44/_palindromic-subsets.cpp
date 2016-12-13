#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int ALPH_SIZE = 26;
const int MOD = 1e9 + 7;

int fat[1 << 17], ifat[1 << 17];

int lazy[1 << 19];
int segt[1 << 19][ALPH_SIZE];

string s;

void build(int node, int lo, int hi) {
  if (lo == hi) {
    segt[node][s[lo]-'a']++;
  } else {
    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);
    for (int i = 0; i < ALPH_SIZE; ++i) {
      segt[node][i] = segt[ls][i] + segt[rs][i];
    }
  }
}

int from, to, val;

void push(int node, bool leaf) {
  if (!lazy[node]) return;
  if (!leaf) {
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    lazy[ls] = (lazy[ls] + lazy[node]) % ALPH_SIZE;
    lazy[rs] = (lazy[rs] + lazy[node]) % ALPH_SIZE;
  }
  rotate(segt[node], segt[node]+ALPH_SIZE-lazy[node], segt[node]+ALPH_SIZE);
  lazy[node] = 0;
}

void update(int node, int lo, int hi) {
  if (from <= lo && hi <= to) {
    lazy[node] = (lazy[node] + val) % ALPH_SIZE;
    push(node, lo == hi);
  } else {
    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;

    push(node, lo == hi);
    push(ls, lo == mid);
    push(rs, (mid+1) == hi);

    if (mid >= from) update(ls, lo, mid);
    if (mid+1 <= to) update(rs, mid+1, hi);
    for (int i = 0; i < ALPH_SIZE; ++i) {
      segt[node][i] = segt[ls][i] + segt[rs][i];
    }
  }
}

int cnt[ALPH_SIZE], prf[ALPH_SIZE], suf[ALPH_SIZE];

void get(int node, int lo, int hi) {
  push(node, lo == hi);
  if (from <= lo && hi <= to) {
    for (int i = 0; i < ALPH_SIZE; ++i) cnt[i] += segt[node][i];
    return;
  }

  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;

  if (mid >= from) get(ls, lo, mid);
  if (mid+1 <= to) get(rs, mid+1, hi);
}

int64 fpw(int64 a, int b) {
  int64 res = 1LL;
  while (b) {
    if (b & 1) { res *= a; res %= MOD; }
    a *= a; a %= MOD;
    b >>= 1;
  }
  return res;
}

int64 count_subsets() {
  for (int i = 0; i < ALPH_SIZE; ++i) {
    prf[i] = ((i ? prf[i-1] : 1) * fpw(2, max(0, cnt[i]-1))) % MOD;
    suf[ALPH_SIZE-i-1] = ((i ? suf[ALPH_SIZE-i] : 1) * fpw(2, max(0, cnt[ALPH_SIZE-i-1]-1))) % MOD;
  }

  int odd = 0;
  for (int i = 0; i < ALPH_SIZE; ++i) {
    auto cur = cnt[i] ? fpw(2, cnt[i]-1) : 0;
    auto this_odd = ((((i ? prf[i-1] : 1) * cur) % MOD) * (((i+1) < ALPH_SIZE) ? suf[i+1] : 1)) % MOD;
    odd += this_odd;
    if (odd >= MOD) odd -= MOD;
  }

  return (suf[0] + odd) % MOD;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  cin >> s;

  build(0, 0, n-1);

  int cmd;
  while (q--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> from >> to >> val;
      update(0, 0, n-1);
    } else {
      cin >> from >> to;
      memset(cnt, 0, sizeof(cnt));
      get(0, 0, n-1);
      cout << (count_subsets()-1+MOD)%MOD << "\n";
    }
  }

  return 0;
}
