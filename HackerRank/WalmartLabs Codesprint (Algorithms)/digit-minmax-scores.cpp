#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 pw[16];

int64 cache[2][4][10][16];
char last_cached[2][4][10][16], cached_now;

string s;

int comp(int a, int b) {
  return (a == b) ? (0) : ((a > b) ? (1) : (2));
}

int64 count(int fre, int cmp, int prv, int pos) {
  if (pos == int(s.size())) return 0LL;

  int64 &res = cache[fre][cmp][prv][pos];
  if (last_cached[fre][cmp][prv][pos] == cached_now) return res;
  last_cached[fre][cmp][prv][pos] = cached_now;

  res = 0LL;

  int mx = fre ? 9 : int(s[pos]-'0');
  for (int cur = 0; cur <= mx; ++cur) {
    int nc = comp(cur, prv);
    int nf = fre || (cur < mx);
    if (nc && cmp && cmp != 3 && nc != cmp) {
      if (nf) {
        res += pw[s.size() - pos - 1];
      } else {
        int64 rm = 0LL;
        for (int j = pos+1; j < int(s.size()); ++j) {
          rm = 10LL*rm + int64(s[j]-'0');
        }
        rm++;
        res += rm;
      }
    }
    if (cmp == 3 && prv == 0) {
      nc = 3;
    }
    res += count(nf, nc, cur, pos+1);
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 a, b;
  cin >> a >> b;

  pw[0] = 1LL;
  for (int i = 1; i < 16; ++i) {
    pw[i] = pw[i-1] * 10LL;
  }

  s = to_string(b); cached_now++;
  int64 rb = count(0, 3, 0, 0);
  s = to_string(a-1LL); cached_now++;
  int64 ra = count(0, 3, 0, 0);

  cout << rb - ra << "\n";

  return 0;
}
