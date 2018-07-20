#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> occurrences_of;
map<pair<int,int>, int> so_cache;
map<int, int> w_cache;

int n;

int all_subarrays(int length) {
  return (length * (length + 1)) / 2;
}

int subarrays_without(const vector<int>& occurrences) {
  int res = 0;
  int prev = 0;
  for (int idx : occurrences) {
    res += all_subarrays(idx - prev - 1);
    prev = idx;
  }
  res += all_subarrays(n - prev);
  return res;
}

int subarrays_without(int x) {
  if (w_cache.count(x)) return w_cache[x];
  return w_cache[x] = subarrays_without(occurrences_of[x]);
}

int subarrays_with_same_occurrences_of(int x, int y) {
  if (x > y) swap(x, y);
  if (so_cache.count({x, y})) return so_cache[{x, y}];

  int sz_x = occurrences_of[x].size();
  int sz_y = occurrences_of[y].size();
  int total = sz_x + sz_y;

  vector<int> combined(total);
  vector<int> value(total);

  int ic = 0, ix = 0, iy = 0;

  while (ix < sz_x && iy < sz_y) {
    if (occurrences_of[x][ix] < occurrences_of[y][iy]) {
      combined[ic] = occurrences_of[x][ix++];
      value[ic++] = 1;
    } else {
      combined[ic] = occurrences_of[y][iy++];
      value[ic++] = -1;
    }
  }
  while (ix < sz_x) {
    combined[ic] = occurrences_of[x][ix++];
    value[ic++] = 1;
  }
  while (iy < sz_y) {
    combined[ic] = occurrences_of[y][iy++];
    value[ic++] = -1;
  }

  int res = subarrays_without(combined);
  int max_len = min(sz_x, sz_y);
  map<int, vector<int>> pref;
  pref[0].push_back(0);
  int cur = 0;
  for (int i = 1; i <= total; ++i) {
    cur += value[i-1];
    if (pref.count(cur)) {
      for (int j : pref[cur]) {
        int lo = combined[j], hi = combined[i-1];
        int prev = j ? combined[j-1] : 0, next = (i < total) ? combined[i] : (n + 1);

        int before = lo - prev - 1;
        int after = next - hi - 1;
        if (before >= 0 && after >= 0) res += (before + 1) * (after + 1);
      }
    }
    pref[cur].push_back(i);
  }

  return so_cache[{x, y}] = res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    int ai; cin >> ai;
    occurrences_of[ai].push_back(i);
  }

  int all = all_subarrays(n);
  while (q--) {
    int x, y;
    cin >> x >> y;

    bool has_x = occurrences_of.count(x) != 0;
    bool has_y = occurrences_of.count(y) != 0;

    if (has_x && has_y) {
      cout << ((x == y) ?  all : subarrays_with_same_occurrences_of(x, y)) << "\n";
    } else if (has_x) {
      cout << subarrays_without(x) << "\n";
    } else if (has_y) {
      cout << subarrays_without(y) << "\n";
    } else { // all subarrays have 0 occurrences of x and y
      cout << all << "\n";
    }

  }

  return 0;
}
