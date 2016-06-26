#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct node_t {
    node_t* chld[26];
    bool seen;
};

int N, ans;
vector<string> grid(2);

node_t* add(node_t *cur, char c) {
  c -= 'a';
  if (cur->chld[c] == NULL) cur->chld[c] = new node_t();
  return cur->chld[c];
}

node_t* bf(node_t *from, int pos, int to_l, int from1) {
  if (to_l) {
    vector<int> rw = {0, 1};
    if (from1) swap(rw[0], rw[1]);
    for (int i = pos; i >= 0; --i) from = add(from, grid[rw[0]][i]);
    for (int i = 0; i <= pos; ++i) from = add(from, grid[rw[1]][i]);
  } else {
    vector<int> rw = {0, 1};
    if (from1) swap(rw[0], rw[1]);
    for (int i = pos; i < N; ++i) from = add(from, grid[rw[0]][i]);
    for (int i = N-1; i >= pos; --i) from = add(from, grid[rw[1]][i]);
  }
  return from;
}

// TODO - s/trie/hash/
void doit(node_t *root, int beg) {
  node_t *cur = add(root, grid[0][beg]);
  cur = bf(cur, beg+1, 0, 0);
  cur = add(cur, grid[1][beg]);
  if (beg == 0) {
    if (!cur->seen) ans++;
    cur->seen = true;
  }

  int from1 = 1;
  for (int i = beg-1; i >= 0; --i) {
    vector<int> rw = {0, 1};
    if (from1) swap(rw[0], rw[1]);

    cur = add(cur, grid[rw[0]][i]);
    node_t *ax = bf(cur, i-1, 1, from1);
    ax = add(ax, grid[rw[1]][i]);
    if (!ax->seen) ans++;
    ax->seen = true;
    cur = add(cur, grid[rw[1]][i]);

    from1 = 1-from1;
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int P;
  cin >> P;
  while (P--) {
    cin >> N;

    for (string &s : grid) { cin >> s; }
    node_t *trie = new node_t();

    ans = 0;
    for (int s = 0; s < 2; ++s) {
      for (int i = 0; i < N; ++i) {
        doit(trie, i);
        swap(grid[0], grid[1]);
        doit(trie, i);
        swap(grid[0], grid[1]);
      }
      for (string &s : grid) {
        reverse(s.begin(), s.end());
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
