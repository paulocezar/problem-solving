#include <bits/stdc++.h>

using namespace std;

enum class State { Void, StartMatch, MiddleMatch };

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;

    int res = 0;
    auto x = State::Void;

    for (char c : s) {
      switch (c) {
        case '0':
          if (x == State::StartMatch)
            x = State::MiddleMatch;
          break;
        case '1':
          if (x == State::MiddleMatch)
            res++;
          x = State::StartMatch;
          break;
        default:
          x = State::Void;
          break;
      }
    }

    cout << res << "\n";
  }

  return 0;
}
