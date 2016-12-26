#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef vector<vector<int>> matrix_t;

struct move_t {
  int i, j, sz;
  move_t(int a = 0, int b = 0, int c = 0) : i(a), j(b), sz(c) {}
};

const int MAXN = 32;
const int MAX_MOVES = 500;

const double EPS = 1e-8;

const double SIZE_CHANGE = .11;
const double SHUFFLE_CHANCE = .52;
const double MUTATION_CHANCE = .97532;

const double LIMIT = 1.9987654321;

const double TEMP_CHANGE = .25;

int sgn(double a) {
  return (a > EPS) ? (+1) : ((a < -EPS) ? (-1) : (0));
}

int cmp(double a, double b) {
  return sgn(a-b);
}

vector<move_t> moves;

int N, OPTIMUM, INITIAL;
int ax1[MAX_MOVES + 1], ax2[MAX_MOVES + 1], ans[MAX_MOVES + 1];

matrix_t grid(MAXN, vector<int>(MAXN));
matrix_t rxax(MAXN, vector<int>(MAXN));

void rotate(matrix_t &m, move_t &mv) {
  for (int i = 0; i < mv.sz; ++i) {
    for (int j = 0; j < mv.sz; ++j) {
      rxax[i][j] = m[mv.i+mv.sz-1-j][mv.j+i];
    }
  }
  for (int i = 0; i < mv.sz; ++i) {
    for (int j = 0; j < mv.sz; ++j) {
      m[mv.i+i][mv.j+j] = rxax[i][j];
    }
  }
}

int eval(matrix_t &m) {
  int res = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int ii = 0; ii < i; ++ii) {
        if (m[ii][j] < m[i][j]) res++;
      }
      for (int jj = 0; jj < j; ++jj) {
        if (m[i][jj] < m[i][j]) res++;
      }
    }
  }

  return res;
}

mt19937 eng;
uniform_real_distribution<double> rnd(0, 1.0);
uniform_int_distribution<int> moves_gen(1, MAX_MOVES);
uniform_int_distribution<int> unif;

void create_random_solution(int* v) {
  v[0] = moves_gen(eng);
  for (int i = 1; i <= v[0]; ++i) {
    v[i] = unif(eng);
  }
  random_shuffle(v+1, v+v[0]+1);
}

int cost(int *sol) {
  auto ax = grid;

  for (int i = 1; i <= sol[0]; ++i) {
    rotate(ax, moves[sol[i]]);
  }

  return eval(ax) - INITIAL;
}

void create_neighbor(int *cur, int *nxt) {
  nxt[0] = cur[0];
  for (int i = 1; i <= nxt[0]; ++i) {
    nxt[i] = cur[i];
  }

  if (cmp(rnd(eng), SIZE_CHANGE) > 0) {
    int nsz = moves_gen(eng);
    if (nsz > nxt[0]) {
      for (int i = nxt[0] + 1; i <= nsz; ++i) {
        nxt[i] = unif(eng);
      }
    }
    nxt[0] = nsz;
  }

  if (cmp(rnd(eng), SHUFFLE_CHANCE) > 0 && nxt[0]) {
    uniform_int_distribution<int> crs(1, nxt[0]);
    int i1 = crs(eng);
    int i2 = crs(eng);
    if (i1 > i2) swap(i1, i2);
    random_shuffle(nxt + i1, nxt+i2+1);
  }

  for (int i = 1; i <= nxt[0]; ++i) {
    if (cmp(rnd(eng), MUTATION_CHANCE) > 0) {
      nxt[i] = unif(eng);
    }
  }

  int prev = cost(nxt);
  while (nxt[0] > 0) {
      nxt[0]--;
      int ths = cost(nxt);
      if (ths <= prev) {
          nxt[0]++;
          break;
      }
      prev = ths;
  }
}

bool should_accept(int cur, int best, double temp) {
  if (cur >= best) return true;
  return cmp(((best - cur) / temp), rnd(eng)) > 0;
}

bool in_good_mood() {
  return cmp(rnd(eng), .888777666) > 0;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  auto t0 = chrono::high_resolution_clock::now();

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  eng = mt19937(seed);

  cin >> N;
  OPTIMUM = N * N * (N - 1);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }

  INITIAL = eval(grid);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int sz = 2;
      int mx = max(i, j);
      while ((mx + sz) <= N) {
        moves.push_back(move_t(i, j, sz));
        sz++;
      }
    }
  }

  unif = uniform_int_distribution<int>(0, moves.size() - 1);

  random_shuffle(moves.begin(), moves.end());
  random_shuffle(moves.begin(), moves.end());

  ans[0] = 0;
  int prev = 0;
  for (int i = moves.size()-1; i >= 0; --i) {
    ans[0]++;
    ans[ans[0]] = i;
    int cur = cost(ans);
    if (cur > prev) {
      prev = cur;
    } else {
      ans[0]--;
    }
    if (ans[0] == MAX_MOVES) break;
  }

  auto has_time = [&t0]() -> bool {
    auto t1 = chrono::high_resolution_clock::now();
    auto time_span = chrono::duration_cast<chrono::duration<double>>(t1 - t0);
    return cmp(time_span.count(), LIMIT) < 0;
  };

  int* current = ax1;
  int* candidate = ax2;

  int res;
  if (!prev) {
    create_random_solution(current);
    res = cost(current);
    if (res > 0) {
      ans[0] = current[0];
      for (int i = 1; i <= ans[0]; ++i) {
        ans[i] = candidate[i];
      }
    }
  } else {
    res = prev;
    current[0] = ans[0];
    for (int i = 1; i <= ans[0]; ++i) {
      current[i] = ans[i];
    }
  }

  double temp = OPTIMUM - INITIAL;
  while (has_time()) {
    create_neighbor(current, candidate);
    temp = temp * TEMP_CHANGE;
    int cur = cost(candidate);

    char ss = 0;
    if (should_accept(cur, res, temp)) {
      swap(current, candidate);
      ss = 1;
    }

    if (cur > res) {
      res = cur;
      if (res > 0) {
        ans[0] = current[0];
        for (int i = 1; i <= ans[0]; ++i) {
          ans[i] = current[i];
        }
      }
    }

    if (in_good_mood() && !ss) {
      swap(current, candidate);
    }
  }

  cout << ans[0] << "\n";
  for (int i = 1; i <= ans[0]; ++i) {
    cout << moves[ans[i]].i + 1 << " " << moves[ans[i]].j + 1 << " " << moves[ans[i]].sz << "\n";
  }

  return 0;
}
