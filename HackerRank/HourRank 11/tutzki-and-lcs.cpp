#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int dp[2][1<<13];

int lcs(string &a, string &b) {
  int n = a.size(), m = b.size();

  int old = 0, cur = 1;
  for (int i = 0; i < m; ++i) dp[old][i] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) dp[cur][j] = (j ? dp[old][j-1] : 0) + 1;
      else dp[cur][j] = 0;
      dp[cur][j] = max(dp[cur][j], max(dp[old][j], (j ? dp[cur][j-1] : 0)));
    }
    old = 1-old;
    cur = 1-cur;
  }

  return dp[old][m-1];
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  int ll = lcs(a, b) + 1;
  int ans = 0;

  string pref = "";
  int n = a.size();
  for (int i = 0; i <= n; ++i) {
    string aa = pref + " " + a.substr(i);
    for (char c : alph) {
      aa[i] = c;
      if (lcs(aa, b) == ll) ans++;
    }
    if (i < n) pref += a[i];
  }


  cout << ans << "\n";

  return 0;
}
