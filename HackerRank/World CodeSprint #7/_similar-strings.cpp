#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct node_t {
  node_t* chld[10];
  int cnt;
};

int mp[10];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  node_t* trie = new node_t();

  for (int i = 0; i < n; ++i) {
    node_t *cur = trie;
    memset(mp, -1, sizeof(mp));
    int chr = 0;

    for (int j = i; j < n; ++j) {
      if (mp[s[j]-'a'] == -1) mp[s[j]-'a'] = chr++;
      if (cur->chld[mp[s[j]-'a']] == NULL) cur->chld[mp[s[j]-'a']] = new node_t();
      cur = cur->chld[mp[s[j]-'a']];
      cur->cnt++;
    }
  }

  while (q--) {
    int l, r; cin >> l >> r; l--, r--;

    memset(mp, -1, sizeof(mp));
    int chr = 0;
    node_t *cur = trie;

    for (int j = l; j <= r; ++j) {
      if (mp[s[j]-'a'] == -1) mp[s[j]-'a'] = chr++;
      cur = cur->chld[mp[s[j]-'a']];
    }

    cout << cur->cnt << "\n";
  }


  return 0;
}
