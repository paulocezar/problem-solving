#include <bits/stdc++.h>

using namespace std;

const int SIDE = 8;
array<string, SIDE> grid;

using Position = pair<int,int>;
using Directions = vector<pair<int,int>>;

bool isvalid(int x) { return 0 <= x && x < SIDE; }
bool isvalid(const Position& p) { return isvalid(p.first) && isvalid(p.second); }

const Directions white_pawn_captures{{-1, -1},{-1, +1}};
const Directions black_pawn_captures{{+1, -1},{+1, +1}};
const Directions side_moves{{-1,0},{0,-1},{1,0},{0,1}};
const Directions diagonal_moves{{-1,-1},{-1,+1},{+1,-1},{+1,+1}};
const Directions knight_moves{{-1,-2},{-2,-1},{-2,+1},{-1,+2},
                              {+1,-2},{+2,-1},{+2,+1},{+1,+2}};

enum class Piece : char {
  King = 'K',
  Queen = 'Q',
  Knight  = 'N',
  Bishop  = 'B',
  Rook = 'R',
  Pawn = 'P'
};
Piece to_piece(char c) { return static_cast<Piece>(toupper(c)); }
bool is_white(const char c) { return isupper(c); }

bool under_attack(const Position& target) {
  const bool target_is_white = is_white(grid[target.first][target.second]);

  auto attacks = [&target](
      const Position& source,
      const Directions& directions,
      const bool multiple_moves_allowed = true) {
    for (const auto& dir : directions) {
      Position pos(source);
      do {
        pos.first += dir.first;
        pos.second += dir.second;
      } while (isvalid(pos) &&
               multiple_moves_allowed &&
               grid[pos.first][pos.second] == '#');
      if (pos == target) return true;
    }
    return false;
  };

  for (int i = 0; i < SIDE; ++i) {
    for (int j = 0; j < SIDE; ++j) {
      if (grid[i][j] == '#' || is_white(grid[i][j]) == target_is_white)
        continue;

      switch (to_piece(grid[i][j])) {
        case Piece::King:
          if (attacks(make_pair(i, j), side_moves, false) ||
              attacks(make_pair(i, j), diagonal_moves, false))
            return true;
          break;
        case Piece::Queen:
          if (attacks(make_pair(i, j), side_moves) ||
              attacks(make_pair(i, j), diagonal_moves))
            return true;
          break;
        case Piece::Knight:
          if (attacks(make_pair(i, j), knight_moves, false))
            return true;
          break;
        case Piece::Bishop:
          if (attacks(make_pair(i, j), diagonal_moves))
            return true;
          break;
        case Piece::Rook:
          if (attacks(make_pair(i, j), side_moves))
            return true;;
          break;
        case Piece::Pawn:
          if (attacks(make_pair(i, j),
                is_white(grid[i][j]) ?
                  white_pawn_captures :
                  black_pawn_captures,
                false))
            return true;
          break;
      }
    }
  }

  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    Position black_king, white_king;
    for (int i = 0; i < SIDE; ++i) {
      cin >> grid[i];
      for (int j = 0; j < SIDE; ++j) {
        if (to_piece(grid[i][j]) == Piece::King) {
          (is_white(grid[i][j]) ? white_king : black_king) = make_pair(i, j);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < SIDE; ++i) {
      if (grid[1][i] == 'P' && grid[0][i] == '#') {
        grid[1][i] = '#';
        grid[0][i] = 'P';
        if (!under_attack(white_king)) {
          for (char c : {'Q', 'R', 'B', 'N'}) {
            grid[0][i] = c;
            res += under_attack(black_king);
          }
        }
        grid[1][i] = 'P';
        grid[0][i] = '#';
      }
    }

    cout << res << "\n";
  }

  return 0;
}
