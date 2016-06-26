#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string winner(char p1, char p2) {
  if (p1 > p2) swap(p1, p2);
  if (p1 == 'P') return ((p2 == 'R') ? "P" : "S");
  return "R";
}

bool ends(string s) {
  while (int(s.size()) > 1) {
    string ss = "";
    for (int i = 0, sz = s.size(); i < sz; i += 2) {
      if (s[i] == s[i+1]) return false;
      ss += winner(s[i], s[i+1]);
    }
    s = ss;
  }
  return true;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, R, P, S;
    cin >> N >> R >> P >> S;
    string s = "";
    while (P--) s += "P";
    while (R--) s += "R";
    while (S--) s += "S";

    cout << "Case #" << tc << ": ";
    bool found = false;
    do {
      if (ends(s)) {
        found = true;
        cout << s << "\n";
        break;
      }
    } while (next_permutation(s.begin(), s.end()));

    if (!found) cout << "IMPOSSIBLE\n";
  }

  return 0;
}
