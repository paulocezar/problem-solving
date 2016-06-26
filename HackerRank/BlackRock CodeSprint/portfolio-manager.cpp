#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct node_t {
  int64 val, dp[2];
  node_t* sons[2];
  node_t(int v) : val(v) {
    sons[0] = sons[1] = NULL;
    dp[0] = dp[1] = -1LL;
  }
};

int64 solve(node_t * node, int bad) {
  if (node == NULL) return 0LL;

  if (node->dp[bad] != -1LL) return node->dp[bad];

  int64 res = solve(node->sons[0], 0) + solve(node->sons[1], 0);
  if (!bad) res = max(res, node->val +  solve(node->sons[0], 1) + solve(node->sons[1], 1));

  node->dp[bad] = res;
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N == 0) { cout << "0\n"; return 0; }

  int64 root_val; cin >> root_val;
  node_t *root = new node_t(root_val);

  queue<node_t*> q;
  q.push(root);

  string val[2];
  while (cin >> val[0]) {
    node_t* cur = q.front(); q.pop();
    cin >> val[1];

    for (int i = 0; i < 2; ++i) {
      if (val[i][0] != '#') {
        cur->sons[i] = new node_t(stoi(val[i]));
        q.push(cur->sons[i]);
      }
    }
  }

  cout << solve(root, 0) << "\n";

  return 0;
}
