#include <bits/stdc++.h>

using namespace std;

using offset = pair<int,int>;
offset operator+(const offset& lhs, const offset& rhs)
{
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}

const vector<offset> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Polyomino {
  set<offset> offsets;
  offset max_offset;

  Polyomino(const set<offset>& raw_offsets) {
    offset grid_offset{0, 0};
    for (const auto& offset : raw_offsets) {
      max_offset.first = max(max_offset.first, offset.first);
      max_offset.second = max(max_offset.second, offset.second);

      if (offset.first < 0) {
        grid_offset.first = 1;
      } else if (offset.second < 0) {
        grid_offset.second = 1;
      }
    }
    max_offset = max_offset + grid_offset;

    for (const auto& offset : raw_offsets) {
      offsets.insert(offset + grid_offset);
    }
  }

  bool operator < (const Polyomino& p) const {
    return offsets < p.offsets;
  }

  static Polyomino base() { return Polyomino{{{0,0}}}; }
};

set<Polyomino> gen_polyominoes(int cells) {
  set<Polyomino> polyominoes{Polyomino::base()};
  while (--cells > 0) {
    set<Polyomino> extended_polyominoes;

    for (const auto& polyomino : polyominoes) {
      auto new_offsets = polyomino.offsets;
      for (const auto& offset : polyomino.offsets) {
        for (const auto& dir : directions) {
          auto new_offset = offset + dir;
          if (new_offsets.insert(new_offset).second) {
            extended_polyominoes.insert({new_offsets});
            new_offsets.erase(new_offset);
          }
        }
      }
    }

    polyominoes = extended_polyominoes;
  }
  return polyominoes;
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> grid(N, vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }

  auto polyominoes = gen_polyominoes(M);
  int res = 0;

  for (const auto& polyomino : polyominoes) {
    int max_i = N - polyomino.max_offset.first - 1;
    int max_j = N - polyomino.max_offset.second - 1;

    for (int i = 0; i <= max_i; ++i) {
      for (int j = 0; j <= max_j; ++j) {
        int cur = 0;
        for (const auto& offset : polyomino.offsets) {
          cur += grid[i + offset.first][j + offset.second];
        }
        res = max(res, cur);
      }
    }
  }

  cout << res << "\n";

  return 0;
}
