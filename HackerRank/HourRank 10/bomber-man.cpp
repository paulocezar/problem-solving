#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef vector<string> state;

int R, C;

void print(state &s) {
  for (string &r : s) {
    for (char c : r) {
      if (c != '.') c = 'O';
      cout << c;
    }
    cout << "\n";
  }
  cout << "\n";
}

void put_bombs(state &s) {
  state ns = s;
  for (string &r : s) {
    for (char &c : r) {
      if (c == '.') c = '3';
      else c = '1';
    }
  }
}

void watch_it_burn(state &s) {
  state ns = s;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (s[i][j] == '1') {
        for (int dx = -1; dx < 2; ++dx) {
          int ni = i + dx;
          int nj = j + dx;
          if (0 <= ni && ni < R) ns[ni][j] = '.';
          if (0 <= nj && nj < C) ns[i][nj] = '.';
          }
        }
      }
    }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      s[i][j] = ns[i][j];
      if (s[i][j] != '.') s[i][j] = '2';
    }
  }

}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> R >> C >> N;

  state grid(R);
  for (string &row : grid) {
    cin >> row;
    for (char &c : row) if (c == 'O') c = '2';
  }

  map<state, int > seen;
  map<int, state> r_seen;
  seen[grid] = 1;
  r_seen[1] = grid;

  int now = 1;
  while (now < N) {
    now++;
    if (now & 1) watch_it_burn(grid);
    else put_bombs(grid);

    if (seen.count(grid)) {
      int c_len = now - seen[grid];
      int rem = N - now;
      rem %= c_len;
      grid = r_seen[seen[grid] + rem];
      now = N;
    } else {
      seen[grid] = now;
      r_seen[now] = grid;
    }

  }
  print(grid);

  return 0;
}
