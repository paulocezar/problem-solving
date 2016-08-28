#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool cache[1024][1024];
char last_cached[1024][1024], cached_now;

string a, b;
int na, nb;

bool solve(int i, int j) {
  if (i == na && j == nb) return true;
  if (i == na) return false;

  bool &res = cache[i][j];
  if (last_cached[i][j] == cached_now) return res;
  last_cached[i][j] = cached_now;
  res = false;

  if (islower(a[i])) {
    res = solve(i+1, j);
    if (!res && (j < nb) && (toupper(a[i]) == b[j])) res = solve(i+1, j+1);
  } else {
    if (a[i] == b[j]) res = solve(i+1, j+1);
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q; cin >> q;
  while (q--) {
    cin >> a >> b;
    na = a.size(), nb = b.size();
    cached_now++;
    if (solve(0, 0)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
