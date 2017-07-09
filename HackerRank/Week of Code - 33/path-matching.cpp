#include <bits/stdc++.h>

using namespace std;

const int LGMN = 17;
const int MAXN = 1 << LGMN;
const int MAXP = 128;

array<vector<int>, MAXN> graph;

array<int, MAXN> depth, parent, treesz;
array<int, MAXN> chain, chainpos, chainleader;

array<char, MAXN> char_at;

namespace KMP {

  int pref[MAXP], pattern_size;
  vector<char> p;

  void build() {
    pattern_size = p.size();
    pref[0] = pref[1] = 0;
    for (int i = 2; i <= pattern_size; ++i) {
      int j = pref[i-1];
      while (p[i-1] != p[j]) {
        if (j == 0) { j = -1; break; }
        j = pref[j];
      }
      pref[i] = ++j;
    }
  }

  pair<int, int> count(int from, int to, int state = 0) {
    int inc = (from < to) ? +1 : -1;
    int occurrences = 0;

    while (from != to) {
      while (state && (p[state] != char_at[from])) state = pref[state];
      if (p[state] == char_at[from]) state++;
      if (state == pattern_size) {
        state = pref[state];
        occurrences++;
      }
      from += inc;
    }
    return {occurrences, state};
  }
}

namespace HLD {
  int cur_chain, pos;
  vector<char> s;

  void explore(int u) {
    treesz[u] = 1;
    for (int v : graph[u]) {
      if (!parent[v]) {
        parent[v] = u;
        depth[v] = depth[u] + 1;
        explore(v);
        treesz[u] += treesz[v];
      }
    }
  }

  void decompose(int u, bool light = true) {
    if (light) {
      ++cur_chain;
      chainleader[cur_chain] = u;
    }
    chain[u] = cur_chain;
    char_at[pos] = s[u-1];
    chainpos[u] = pos++;

    int mx = -1;
    for (int v : graph[u]) {
      if ((parent[v] == u) &&
          ((mx == -1) || (treesz[mx] < treesz[v])))
        mx = v;
    }
    if (mx != -1) {
      decompose(mx, false);
    }
    for (int v : graph[u]) {
      if ((parent[v] == u) && (v != mx)) {
        decompose(v);
      }
    }
  }

  void build() {
    parent[1] = 1;
    depth[1] = 0;
    cur_chain = -1, HLD::pos = 0;
    explore(1);
    decompose(1);
  }

  int lca(int u, int v) {
    while (chain[u] != chain[v]) {
      if (depth[chainleader[chain[u]]] < depth[chainleader[chain[v]]]) {
        v = parent[chainleader[chain[v]]];
      } else {
        u = parent[chainleader[chain[u]]];
      }
    }
    if (depth[u] < depth[v]) return u;
    return v;
  }
}

namespace segtree {
  struct node_t {
    pair<int, int> up_down, down_up;
  };

  array<node_t, 1 << (LGMN + 1)> tree;
  node_t ans;

  void merge(node_t& node, const node_t& l, const node_t& r, int lo, int mid, int hi) {
    // take occurrences crossing from l to r
    int x = max(lo, mid - KMP::pattern_size + 2);
    int y = min(hi, mid + KMP::pattern_size - 1);
    tree.back().up_down = KMP::count(mid, x-1, r.up_down.second);
    tree.back().down_up = KMP::count(mid+1, y+1, l.down_up.second);

    // add occurrences happening only on child
    tree.back().up_down.first += l.up_down.first + r.up_down.first;
    tree.back().down_up.first += l.down_up.first + r.down_up.first;

    // get the states for this node
    x = min(hi, lo + KMP::pattern_size - 1);
    y = max(lo, hi - KMP::pattern_size + 1);
    tree.back().up_down.second = KMP::count(x, lo-1, 0).second;
    tree.back().down_up.second = KMP::count(y, hi+1, 0).second;

    node = tree.back();
  }

  void build(int node = 0, int lo = 0, int hi = HLD::s.size() - 1) {
    if (lo == hi) {
      tree[node].up_down = KMP::count(hi, hi-1, 0);
      tree[node].down_up = KMP::count(lo, lo+1, 0);
    } else {
      int mid = (lo+hi) >> 1;
      int ls = (node << 1) + 1;
      int rs = ls + 1;
      build(ls, lo, mid);
      build(rs, mid+1, hi);
      merge(tree[node], tree[ls], tree[rs], lo, mid, hi);
    }
  }

  int from, to;
  void get(int node = 0, int lo = 0, int hi = HLD::s.size() - 1) {
    if (from <= lo && hi <= to) {
      if (lo == from) ans = tree[node];
      else merge(ans, ans, tree[node], from, lo-1, hi);
      return;
    }

    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;

    if (from <= mid) get(ls, lo, mid);
    if (to >= (mid+1)) get(rs, mid+1, hi);
  }

  pair<int,int> query(int l, int r) {
    from = l;
    to = r;
    bool want_up_down = false;

    if (from > to) {
      swap(from, to);
      want_up_down = true;
    }

    get();

    if (want_up_down) return ans.up_down;
    return ans.down_up;
  }
}

namespace problem {
  vector<pair<int,int>> interesting;

  void get_intervals_on_path(int to, int from, bool rev = false) {
    do {
      if (chain[from] == chain[to]) {
        if (chainpos[to] < chainpos[from]) {
          interesting.emplace_back(chainpos[to]+1, chainpos[from]);
          if (rev) swap(interesting.back().first, interesting.back().second);
        }
        return;
      } else {
        interesting.emplace_back(chainpos[chainleader[chain[from]]], chainpos[from]);
        if (rev) swap(interesting.back().first, interesting.back().second);
        from = parent[chainleader[chain[from]]];
      }
    } while (true);
  }

  int solve(int u, int v) {
    // if u == v we can only match if pattern has size 1
    if (u == v)
      return ((KMP::pattern_size == 1) &&
              (HLD::s[u-1] == KMP::p[0])) ? 1 : 0;

    int lca = HLD::lca(u, v);
    interesting.clear();

    get_intervals_on_path(lca, u, true);
    interesting.emplace_back(chainpos[lca], chainpos[lca]);
    int prev = interesting.size();
    get_intervals_on_path(lca, v);
    reverse(interesting.begin()+prev, interesting.end());

    int res = 0, state = -1;
    for (auto& interval : interesting) {
      auto cur = segtree::query(interval.first, interval.second);
      res += cur.first;

      if (state == -1) {
        state = cur.second;
      } else {
        int dir = (interval.first > interval.second) ? -1 : +1;
        int x = interval.first + (KMP::pattern_size-1)*dir - dir;

        if (dir == -1) x = max(x, interval.second);
        else x = min(x, interval.second);

        auto ax = KMP::count(interval.first, x + dir, state);
        res += ax.first;

        if ((abs(interval.first - interval.second)+1) >= KMP::pattern_size)
          state = cur.second;
        else state = ax.second;
      }
    }
    return res;
  }
}

int get_int() {
  char c = getchar_unlocked();
  while (!isdigit(c)) c = getchar_unlocked();
  int res = 0;
  while (isdigit(c)) {
    res = 10*res + int(c-'0');
    c = getchar_unlocked();
  }
  return res;
}

void read(vector<char> &v) {
  char c = getchar_unlocked();
  while (!isalpha(c)) c = getchar_unlocked();
  while (isalpha(c)) {
    v.push_back(c);
    c = getchar_unlocked();
  }
}

int main(int argc, char* argv[]) {

  int n, q;
  n = get_int();
  q = get_int();

  HLD::s.reserve(n);
  KMP::p.reserve(128);
  read(HLD::s);
  read(KMP::p);

  for (int i = 1; i < n; ++i) {
    int u, v;
    u = get_int();
    v = get_int();
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  KMP::build();
  HLD::build();
  segtree::build();

  while (q--) {
    int u, v;
    u = get_int();
    v = get_int();
    printf("%d\n", problem::solve(u, v));
  }

  return 0;
}
