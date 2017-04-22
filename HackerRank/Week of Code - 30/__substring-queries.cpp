#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 16;

class suffix_automata {
public:
  struct state_t {
    int len, link;
    map< char, int > next;
  };

  int sz, last;
  vector<state_t> state;

  suffix_automata(int max_len) {
    state.resize(2 * max_len);
    sz = last = 0;
    state[0].len = 0;
    state[0].link = -1;
    ++sz;
  }

  void add(char c) {
    int p, cur = sz++;
    state[cur].len = state[last].len+1;
    for (p = last; p != -1 && !state[p].next.count(c); p = state[p].link)
      state[p].next[c] = cur;
    if (p == -1) state[cur].link = 0;
    else {
      int q = state[p].next[c];
      if (state[p].len+1 == state[q].len) state[cur].link = q;
      else {
        int clone = sz++;
        state[clone].len = state[p].len+1;
        state[clone].next = state[q].next;
        state[clone].link = state[q].link;
        for (; p != -1 && state[p].next[c]==q; p=state[p].link)
          state[p].next[c] = clone;
        state[q].link = state[cur].link = clone;
      }
    }
    last = cur;
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  vector<suffix_automata> sa;
  vector<string> s(n);

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    sa.emplace_back(suffix_automata(s[i].size()));
    for (char c : s[i]) {
      sa[i].add(c);
    }
  }

  while (q--) {
    int a, b; cin >> a >> b;

    if (s[a].size() > s[b].size()) swap(a, b);

    int v = 0, l = 0, best = 0;
    for (char c : s[a]) {
      while (v && ! sa[b].state[v].next.count(c)) {
        v = sa[b].state[v].link;
        l = sa[b].state[v].len;
      }
      if (sa[b].state[v].next.count(c)) {
        v = sa[b].state[v].next[c];
        ++l;
      }
      if (l > best)
        best = l;
    }

    cout << best << "\n";
  }

  return 0;
}
