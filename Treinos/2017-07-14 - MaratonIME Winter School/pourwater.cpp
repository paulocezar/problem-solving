#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                    { 0, -1},          { 0, 1},
                                    { 1, -1}, { 1, 0}, { 1, 1}};

array<array<bool, 30>, 30> inside;

void flood(const vector<string>& b, int i, int j) {
  if (i < 0 || j < 0 || i >= (int)b.size() || j >= (int)b.size()) return;
  if (inside[i][j] || b[i][j] == '#') return;
  inside[i][j] = true;
  for (auto& d : DIRECTIONS) {
    flood(b, i + d.first, j + d.second);
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<string> bottle(n);
  for (auto&v : bottle) cin >> v;

  int w;
  cin >> w;

  flood(bottle, 0, 1);

  for (int i = n-1; w && i >= 0; --i) {
    for (int j = 0; w && j < n; ++j) {
      if (bottle[i][j] == '.' && inside[i][j]) {
        bottle[i][j] = '*'; w--;
      }
    }
  }

  for (auto& v: bottle) cout << v << "\n";

  return 0;
}
