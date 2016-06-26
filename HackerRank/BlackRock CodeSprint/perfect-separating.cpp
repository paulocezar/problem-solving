#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
string s;

unordered_map<int, int64> cache[64][64];

int64 solve(int i, int j, int mask) {
  int at = i+j;
  if (at == N) return ((i == j) ? 1LL : 0LL);
  if (cache[i][j].count(mask)) return cache[i][j][mask];

  int64 res = 0LL;
  int cur = s[at] - 'a';
  int dif = abs(i-j);

  if (i == j) {
    res += solve(i+1, j, (mask << 1) | cur);
    res += solve(i, j+1, (mask << 1) | cur);
  } else {
    int head = (mask >> (dif-1)) & 1;
    int tail  = (1 << (dif-1)) - 1;
    int rem = N - at - 1;

    if (i > j) {
      if (dif < rem) res += solve(i+1, j, (mask << 1) | cur);
      if (cur == head) res += solve(i, j+1, mask & tail);
    } else {
      if (cur == head) res += solve(i+1, j, mask & tail);
      if (dif < rem) res += solve(i, j+1, (mask << 1) | cur);
    }
  }

  cache[i][j][mask] = res;
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> s;
  N = s.size();

  if (N & 1) cout << "0\n";
  else cout << solve(0, 0, 0) << "\n";

  return 0;
}
