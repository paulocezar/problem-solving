#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

vector<int> gr[MAXN];
int in_deg[MAXN];
int pred_seen[MAXN];
int orig_topo[MAXN];
int new_topo[MAXN];
int n;

bool find_greater(int keeping, bool build = false) {

    set<int> q;
    for (int i = 1; i <= n; ++i) {
      pred_seen[i] = 0;
      if (pred_seen[i] == in_deg[i]) {
        q.insert(i);
      }
    }

    bool found = false;
    int cur_pos = 0, u;
    while (cur_pos < n) {
      if (cur_pos <= keeping) {
        u = orig_topo[cur_pos];
      } else if (!found) {
        auto gr = q.upper_bound(orig_topo[cur_pos]);
        if (gr != q.end()) {
          found = true;
          u = *gr;
          if (!build) break;
        } else {
          u = orig_topo[cur_pos];
        }
      } else {
        u = * q.begin();
      }
      new_topo[cur_pos++] = u;
      q.erase(u);

      for (int v : gr[u]) {
        pred_seen[v]++;
        if (pred_seen[v] == in_deg[v]) {
          q.insert(v);
        }
      }
    }

    return found;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    while (m--) {
      int u, v; cin >> u >> v;
      gr[u].push_back(v);
      in_deg[v]++;
    }

    for (int i = 0; i < n; ++i) {
      cin >> orig_topo[i];
    }

    int lo = 0, hi = n-1;
    while (lo <= hi) {
      int mid = (lo+hi) >> 1;
      if (find_greater(mid)) {
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }

    bool ok = find_greater(hi, true);
    if (ok) {
      for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << new_topo[i];
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }

    return 0;
}
