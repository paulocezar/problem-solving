#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int lcs[2][256];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string t;
  cin >> t;

  vector<string> p;
  string s;
  string ss = "";
  while (cin >> s) {
    p.push_back(s);
    ss += s;
  }

  vector< int > matches;
  int lo = 0;
  for (string &w : p) {
    auto found = t.find(w, lo);
    if (found != string::npos) {
      matches.push_back(found);
      lo = found + 1;
    } else break;
  }

  if (p.size() == matches.size()) {
    cout << "YES\n";
    int i = 0;
    for (string &w : p) {
      if (i) cout << ' ';
      cout << w << ' ' << matches[i] << ' ' << matches[i] + w.size() - 1;
      ++i;
    }
    cout << "\n";

    int n = t.size();
    int m = ss.size();

    int old = 0, cur = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        lcs[cur][j] = max(lcs[old][j], j ? lcs[cur][j-1] : 0);
        if (t[i] == ss[j]) lcs[cur][j] = max(lcs[cur][j], 1 + (j ? lcs[old][j-1] : 0));
      }
      old = 1-old;
      cur = 1-cur;
    }
    int cost = n - lcs[old][m-1];
    cost += m - lcs[old][m-1];
    cost += p.size() - 1;
    cout << cost << "\n";
  } else {
    cout << "NO\n";
    if (matches.size()) {
      int i = 0;
      for (int m : matches) {
        if (i) cout << ' ';
        string &w = p[i];
        cout << w << ' ' << m << ' ' << m + w.size() - 1;
        ++i;
      }
      cout << "\n";
    } else cout << "0\n";
    cout << "0\n";
  }


  return 0;
}
