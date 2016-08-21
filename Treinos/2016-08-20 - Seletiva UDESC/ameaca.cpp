#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXM = 1<<14;
const int MAXN = 1<<8;

const double EPS = 1e-9;

int sgn(double a) {
  return ((a > EPS) ? (1) : ((a < -EPS) ? (-1): (0)));
}
int cmp(double a, double b) {
  return sgn(a-b);
}

pair<double, pair<int, int> > edges[MAXM];
double best[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, Q;
  while (cin >> N >> M && (N || M)) {

    for (int i = 0; i < M; ++i) {
      cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
      edges[i].first /= 100.0;
    }

    cin >> Q;
    cout << fixed << setprecision(2);
    while (Q--) {
      int u, v; cin >> u >> v;

      for (int i = 1; i <= N; ++i) {
        best[i] = 1.0;
      }
      best[u] = 0.0;
      int repeat = N - 1;
      while (repeat--) {
        bool change = false;
        for (int i = 0; i < M; ++i) {
          double w = edges[i].first;
          int from = edges[i].second.first;
          int to = edges[i].second.second;
          int doit = 2;
          while (doit--) {
            double np = 1.0 - ((1.0 - best[from]) * (1.0 - w));
            if (cmp(np, best[to]) < 0) {
              best[to] = np;
              change = true;
            }
            swap(from, to);
          }
        }
        if (!change) break;
      }

      bool cycle = false;
      for (int i = 0; i < M; ++i) {
        double w = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;
        int doit = 2;
        while (doit--) {
          double np = 1.0 - ((1.0 - best[from]) * (1.0 - w));
          if (cmp(np, best[to]) < 0) {
            cycle = true;
          }
          swap(from, to);
        }
      }

      double ans = 0.0;
      if (!cycle) ans = 100.0 * best[v];

      cout << ans << "%\n";
    }
    cout << "\n";
  }

  return 0;
}
