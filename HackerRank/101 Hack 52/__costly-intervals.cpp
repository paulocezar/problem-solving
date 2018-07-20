#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100'000;
const int MAXSZ = 1 << 18;

array<int, MAXN> a;
array<int, MAXSZ> st;

int from, to, len;
void update(int node, int lo, int hi) {
  if (from <= lo && hi <= to) {
    st[node] = max(st[node], len);
    return;
  }
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  int mid = (lo + hi) >> 1;
  if (from <= mid) update(ls, lo, mid);
  if (to >= mid+1) update(rs, mid+1, hi);
}

void propagate(int node, int lo, int hi) {
  if (lo == hi) return;
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  int mid = (lo + hi) >> 1;
  st[ls] = max(st[ls], st[node]);
  st[rs] = max(st[rs], st[node]);
  propagate(ls, lo, mid);
  propagate(rs, mid+1, hi);
}

int get(int node, int lo, int hi) {
  if (lo == hi) return st[node] ? st[node] : -1;
  int mid = (lo + hi) >> 1;
  if (from <= mid) return get((node << 1) + 1, lo, mid);
  return get((node << 1) + 2, mid+1, hi);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> ok;

  for (int i = 0; i < n; ++i) {

    int mx = a[i];
    int mn = a[i];
    int all = a[i];
    int some = a[i];
    len = 0;
    for (int j = i; j < n; ++j) {
      len++;
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      all = all & a[j];
      some = some | a[j];
      int cost = (some - all) - (mx - mn);
      if (cost >= k) {
        from = i, to = j;
        update(0, 0, n-1);
      }
    }
  }

  propagate(0, 0, n-1);

  for (int i = 0; i < n; ++i) {
    from = i;
    cout << get(0, 0, n-1) << "\n";
  }

  return 0;
}
