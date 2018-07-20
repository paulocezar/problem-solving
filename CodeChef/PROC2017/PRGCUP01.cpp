#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto x = {-2, -1, 1, 2};
  vector<pair<int,int>> directions;
  for (int i : x) {
    for (int j : x) {
      if (abs(i) == abs(j)) continue;
      directions.emplace_back(i, j);
    }
  }

  using state = pair<int,int>;
  auto ok = [](const state& s) -> bool {
    #define inside(x) (1 <= (x) && (x) <= 8)
    return inside(s.first) && inside(s.second);
  };

  auto get_state = [](string s) {
    return state{s[1]-'1'+1, s[0]-'a'+1};
  };

  int t;
  cin >> t;
  while (t--) {
    string from, to;
    cin >> from >> to;

    state s = get_state(from);
    state t = get_state(to);

    map<state, int> seen;
    queue<state> q;
    seen[s] = 0;
    q.push(s);

    while (!q.empty()) {
      auto c = q.front(); q.pop();
      for (auto& d : directions) {
        state nw{c.first + d.first, c.second + d.second};
        if (ok(nw) && !seen.count(nw)) {
          seen[nw] = seen[c] + 1;
          q.push(nw);
        }
      }
    }

    cout << seen[t] << "\n";
  }

  return 0;
}
