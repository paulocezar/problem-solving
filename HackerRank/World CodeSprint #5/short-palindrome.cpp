#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1e9 + 7;

int cnt[1<<20][1<<5];



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();

  cnt[0][s[0]-'a'] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 26; ++j) cnt[i][j] = cnt[i-1][j];
    cnt[i][s[i]-'a']++;
  }

  map<int, int> cnt2;
  vector<int> nxt(26, 0);
  nxt[s[n-1]-'a']++;

  int64 res = 0LL;
  for (int i = n-2; i > 0; --i) {

    int b = s[i]-'a';
    for (int a = 0; a < 26; ++a) {
      int ab = cnt[i-1][a];
      int ba = 26 * b + a;
      res += (int64(ab) * int64(cnt2[ba])) % mod;
      res %= mod;
    }

    int c = 26 * (s[i]-'a');
    for (int d = 0; d < 26; ++d) {
      cnt2[c + d] += nxt[d];
      cnt2[c + d] %= mod;
    }
    nxt[s[i]-'a']++;
  }
  cout << res << "\n";

  return 0;
}
