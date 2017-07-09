#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
using namespace __gnu_pbds;

const int MAXN  = 1 << 17;

using ordered_set = tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>;

struct node_t {
  ordered_set vals;
} segt[MAXN * 4];

int x[MAXN], f[MAXN], p[MAXN], tin[MAXN], tout[MAXN], inv[MAXN], timer;

vector<int> gr[MAXN];

void dfs(int u) {
  tin[u] = ++timer;
  for (int v : gr[u]) {
    dfs(v);
  }
  tout[u] = timer;
}

void build(int node, int lo, int hi) {

  if (lo == hi) {
    segt[node].vals.insert({x[inv[lo]], lo});
    return;
  }

  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  build(ls, lo, mid);
  build(rs, mid+1, hi);

  if (segt[ls].vals.size() < segt[rs].vals.size()) {
    segt[node].vals = segt[rs].vals;
    for (auto &v : segt[ls].vals) segt[node].vals.insert(v);
  } else {
    segt[node].vals = segt[ls].vals;
    for (auto &v : segt[rs].vals) segt[node].vals.insert(v);
  }
}

int pos, val;
void update(int node, int lo, int hi) {
  segt[node].vals.erase({x[inv[pos]], pos});
  segt[node].vals.insert({val, pos});

  if (lo == hi) {
    x[inv[pos]] = val;
    return;
  }

  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;

  if (pos <= mid) update(ls, lo, mid);
  else update(rs, mid+1, hi);
}

int from, to;
int get(int node, int lo, int hi) {
  if (lo > to || hi < from) return 0;
  if (from <= lo && hi <= to) {
    return segt[node].vals.order_of_key({val, 1e9});
  }
  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  int res = get(ls, lo, mid) + get(rs, mid+1, hi);
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    int pi;
    cin >> pi >> x[i];
    if (pi) gr[pi].push_back(i);
  }

  timer = 0;
  dfs(1);
  for (int i = 1; i <= N; ++i) {
    inv[tin[i]] = i;
  }
  build(0, 1, timer);

  int t, i, y;
  while (cin >> t >> i >> y) {
    if (t == 1) {
      pos = tin[i], val = y;
      update(0, 1, timer);
    } else {
      val = y;
      from = tin[i], to = tout[i];
      cout << get(0, 1, timer) << "\n";
    }
  }

  return 0;
}
