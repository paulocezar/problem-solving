#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int DIM = 4;

typedef pair<int,int> dir_t;
typedef pair<int,int> pos_t;
typedef array<array<char,DIM>,DIM> state_t;

typedef int Player;
#define WHITE 0
#define BLACK 1

typedef char Piece;
#define QUEEN 'Q'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define PAWN 'P'
#define EMPTY  '.'

#define QUEEN_VALUE 1024
#define ROOK_VALUE 32
#define KNIGHT_VALUE 8
#define BISHOP_VALUE 8
#define PAWN_VALUE 2

#define INF (2 * QUEEN_VALUE)

random_device rd;
mt19937 eng(rd());

vector<vector<Piece>> promos = {{ROOK, KNIGHT, BISHOP},
                                {tolower(ROOK), tolower(KNIGHT), tolower(BISHOP)}};

auto combine = [](vector<dir_t> &a, vector<dir_t> &b){
  vector<dir_t> x(a);
  x.insert(x.end(), b.begin(), b.end());
  shuffle(x.begin(), x.end(), eng);
  return x;
};

auto shuffled = [](vector<dir_t> orig) {
  shuffle(orig.begin(), orig.end(), eng);
  return orig;
};

auto traverse = [](){
  vector<pos_t> r;
  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      r.push_back({i, j});
    }
  }
  shuffle(r.begin(), r.end(), eng);
  return r;
};

inline bool inside(pos_t &p) {
  return 0 <= p.first && p.first < DIM &&
         0 <= p.second && p.second < DIM;
}

inline Piece enemy_queen(Player cur) {
  return (cur == WHITE) ? tolower(QUEEN) : QUEEN;
}

inline int promotion_border(Player cur) {
  return (cur == WHITE) ? 3 : 0;
}

vector<pos_t> cells = traverse();

vector<dir_t> line = {{ 0,-1}, {-1, 0}, { 0, 1}, { 1, 0}};
vector<dir_t> diag = {{-1,-1}, {-1, 1}, { 1, 1}, { 1, -1}};

map<Piece, vector<dir_t>> moves = {
  {KNIGHT, {{-1,-2}, {-2,-1}, {-2, 1}, {-1, 2},
            { 1, 2}, { 2, 1}, { 2,-1}, { 1,-2}}},
  {BISHOP, shuffled(diag)},
  {ROOK,   shuffled(line)},
  {QUEEN,  combine(line, diag)},
};

state_t board;

vector<pos_t> getPawnNeighbors(Player cur, pos_t pos, bool caps) {
  vector<pos_t> ng;

  int dx = 1;
  if (cur == BLACK) dx = -1;

  if (caps) {
    for (auto &dy : {-1, +1}) {
      pos_t npos = pos;
      npos.first += dx;
      npos.second += dy;

      if (!inside(npos)) continue;

      if (board[npos.first][npos.second] == EMPTY) continue;
      if (isupper(board[npos.first][npos.second]) != isupper(board[pos.first][pos.second])) {
        ng.push_back(npos);
      }
    }
  } else {
    pos.first += dx;
    if (!caps && inside(pos) && (board[pos.first][pos.second] == EMPTY)) {
      ng.push_back(pos);
    }
  }

  return ng;
}

vector<pos_t> getKnightNeighbors(pos_t pos, bool caps) {
  vector<pos_t> ng;

  for (auto &dir : moves[KNIGHT]) {
    pos_t npos = pos;
    npos.first += dir.first;
    npos.second += dir.second;

    if (!inside(npos)) continue;

    if (board[npos.first][npos.second] == EMPTY) {
      if (!caps) ng.push_back(npos);
    } else if (caps) {
      if (isupper(board[npos.first][npos.second]) != isupper(board[pos.first][pos.second])) {
        ng.push_back(npos);
      }
    }
  }

  if (!caps) shuffle(ng.begin(), ng.end(), eng);
  return ng;
}

vector<pos_t> getNeighbors(pos_t pos, vector<dir_t> &dirs, bool caps) {
  vector<pos_t> ng;

  for (auto &dir : dirs) {
    pos_t npos = pos;
    while (true) {
      npos.first += dir.first;
      npos.second += dir.second;

      if (!inside(npos)) break;

      if (board[npos.first][npos.second] == EMPTY) {
        if (!caps) ng.push_back(npos);
      } else {
        if (caps && (isupper(board[npos.first][npos.second]) != isupper(board[pos.first][pos.second]))) {
          ng.push_back(npos);
        }
        break;
      }
    }
  }

  if (!caps) shuffle(ng.begin(), ng.end(), eng);
  return ng;
}

int evaluate() {
  int score = 0;
  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      if (board[i][j] == EMPTY) continue;
      int sgn = isupper(board[i][j]) ? +1 : -2;
      switch(toupper(board[i][j])) {
        case QUEEN: score += sgn * QUEEN_VALUE; break;
        case ROOK: score += sgn * ROOK_VALUE; break;
        case BISHOP: score += sgn * BISHOP_VALUE; break;
        case KNIGHT: score += sgn * KNIGHT_VALUE; break;
        case PAWN: score += sgn * PAWN_VALUE; break;
      }
    }
  }
  return score;
}

int minimax(Player cur, int remaining_moves, int alpha = -INF, int beta = +INF) {

  if (remaining_moves == 0) {
    return evaluate();
  }

  vector<pos_t> pieces;

  for (auto &c : cells) {
    if (board[c.first][c.second] == EMPTY) continue;
    if ((isupper(board[c.first][c.second])?WHITE:BLACK) == cur) {
      pieces.push_back(c);
    }
  }

  shuffle(pieces.begin(), pieces.end(), eng);

  int score = (cur == WHITE) ? -INF : +INF;
  for (bool capture : {true, false}) {
    for (auto &p : pieces) {

      vector<pos_t> neighbors;

      Piece piece = board[p.first][p.second];

      switch(toupper(piece)) {
        case PAWN:
          neighbors = getPawnNeighbors(cur, p, capture);
          break;
        case KNIGHT:
          neighbors = getKnightNeighbors(p, capture);
          break;
        case BISHOP:
        case ROOK:
        case QUEEN:
          neighbors = getNeighbors(p, moves[toupper(piece)], capture);
          break;
      }

      board[p.first][p.second] = EMPTY;
      for (auto &pos : neighbors) {
        Piece prev = board[pos.first][pos.second];
        if (prev == enemy_queen(cur)) {
          board[p.first][p.second] = piece;
          return (cur == WHITE) ? QUEEN_VALUE : -QUEEN_VALUE;
        }

        vector<Piece> possibilites;
        if ((toupper(piece) == PAWN) && (pos.first == promotion_border(cur))) {
          possibilites = promos[cur];
        } else {
          possibilites = {piece};
        }

        for (Piece pp : possibilites) {
          board[pos.first][pos.second] = pp;

          if (cur == WHITE) {
            score = max(score, minimax(1 - cur, remaining_moves - 1, alpha, beta));
            alpha = max(alpha, score);
            if (beta <= alpha) {
              board[pos.first][pos.second] = prev;
              board[p.first][p.second] = piece;
              return score;
            }
          } else {
            score = min(score, minimax(1 - cur, remaining_moves - 1, alpha, beta));
            beta = min(beta, score);
            if (beta <= alpha) {
              board[pos.first][pos.second] = prev;
              board[p.first][p.second] = piece;
              return score;
            }
          }
        }

        board[pos.first][pos.second] = prev;
      }
      board[p.first][p.second] = piece;
    }
  }

  return score;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    int pieces[2], m;

    for (auto &r : board) {
      for (auto &c : r) {
        c = EMPTY;
      }
    }

    cin >> pieces[WHITE] >> pieces[BLACK] >> m;

    char t, c; int r;

    for (int player = 0; player < 2; ++player) {
      for (int i = 0; i < pieces[player]; ++i) {
        cin >> t >> c >> r;

        if (player == WHITE) t = toupper(t);
        else t = tolower(t);

        board[r-1][c-'A'] = t;
      }
    }

    if (minimax(WHITE, m) >= QUEEN_VALUE) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
