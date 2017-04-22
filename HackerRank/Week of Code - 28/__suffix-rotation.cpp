#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    string s; cin >> s;
    string ss = s;
    sort(ss.begin(), ss.end());
    int n = s.size();

    set<string> seen;
    queue<string> q;

    int ax = 0;
    while (ax < n && s[ax] == ss[ax]) ax++;
    s = s.substr(ax);
    seen.insert(s);

    if (s.size()) q.push(s);
    else cout << "0\n";

    bool found = false;
    int step = 0;
    while (!found && !q.empty()) {
      int sz = q.size();
      while (!found && sz--) {
        auto cur = q.front(); q.pop();
        int nn = cur.size();

        int pos = n - nn;
        for (int i = 0; !found && i < nn; ++i) {
          if (cur[i] == ss[pos]) {
            string nx = cur.substr(i) + cur.substr(0, i);
            ax = 0;
            while (ax < nn && nx[ax] == ss[pos+ax]) ax++;
            nx = nx.substr(ax);
            if (nx.size() == 0) {
              cout << step + 1 << "\n";
              found = true;
            } else if (!seen.count(nx)) {
              seen.insert(nx);
              q.push(nx);
            }
          }
        }
      }
      step++;
    }
  }

  return 0;
}
