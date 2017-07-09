#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct candies_at {
  int i, j, b;
  candies_at(int ii, int jj, int bb) : i(ii), j(jj), b(bb) {}
};

int A[128], C[128];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < m; ++i) cin >> C[i];

  vector<candies_at> B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int bb; cin >> bb;
      B.emplace_back(candies_at(i, j, bb));
    }
  }

  sort(B.begin(), B.end(), [](const candies_at& a, const candies_at& b) -> bool {
    if (a.b != b.b) return a.b > b.b;
    if (A[a.i] != A[b.i]) return A[a.i] < A[b.i];
    return C[a.j] > C[b.j];
  });

  int res = 0;
  for (auto &c : B) {
    if (A[c.i]) {
      if (C[c.j] > 0) {
        C[c.j]--;
        A[c.i]--;
        res += c.b;
      } else {
        int ox = abs(C[c.j]);
        int nx = ox + 1;
        int add = c.b - (nx*nx - ox*ox);
        if (add > 0) {
          C[c.j]--;
          A[c.i]--;
          res += add;
        }
      }
    }
  }
  cout << res << "\n";

  return 0;
}
