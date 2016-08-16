#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int set_at[1<<17], xord_at[1<<17];
pair<unsigned, unsigned> val[1<<17], xord[1<<17];

unsigned get_idx(string &s) {
  unsigned res = 0u;
  for (char c : s) {
    res <<= 1;
    if (c == '1') res++;
  }
  return res;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m, q; unsigned idx, x; string s;
  cin >> n >> m;
  int sets = 0, xors = 0;

  for (int i = 1; i <= m; ++i) {
    cin >> q;
    switch (q) {
      case 1: cin >> x >> s;
              idx = get_idx(s);
              val[sets].first = idx, val[sets].second = x;
              set_at[sets++] = i;
              break;
      case 2: cin >> x >> s;
              idx = get_idx(s);
              xord[xors].first = idx, xord[xors].second = x;
              xord_at[xors++] = i;
              break;
      case 3: cin >> s;
              idx = get_idx(s);
              x = 0u;
              int j = sets - 1;
              while (j >= 0) {
                if ((val[j].first & idx) == idx) {
                  x = val[j].second; break;
                }
                j--;
              }
              int k = xors - 1;
              while (k >= 0) {
                if ((j >= 0) && (xord_at[k] < set_at[j])) break;
                if ((xord[k].first & idx) == idx) {
                  x ^= xord[k].second;
                }
                k--;
              }
              cout << x << "\n";
              break;
    }
  }

  return 0;
}
