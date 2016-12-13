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

int cnt[ALPH_SIZE];

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

int64 C(int n, int k) {
  if (n < k) return 0LL;
  return (((fat[n] * ifat[n-k])%MOD) * ifat[k])%MOD;
}

int64 count_subsets(int cur = 0, bool odd = false) {
  if (cur == ALPH_SIZE) return 1LL;

  int64 res = 0LL;

  for (int use = 0; use <= cnt[cur]; use += 2) {
    res += (C(cnt[cur], use) * count_subsets(cur+1, odd)) % MOD;
    if (res >= MOD) res -= MOD;
  }

  if (!odd) {
    for (int use = 1; use <= cnt[cur]; use += 2) {
      res += (C(cnt[cur], use) * count_subsets(cur+1, true)) % MOD;
      if (res >= MOD) res -= MOD;
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  cin >> s;

  build(0, 0, n-1);

  fat[0] = 1LL, ifat[0] = 1LL;
  fat[1] = 1LL, ifat[1] = 1LL;
  for (int i = 2; i <= n; ++i) {
    fat[i] = (int64(i) * fat[i-1]) % MOD;
    ifat[i] = fpw(fat[i], MOD-2);
  }

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
