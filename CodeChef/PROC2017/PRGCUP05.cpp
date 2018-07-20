#include <bits/stdc++.h>

using namespace std;

using row = vector<int>;
using matrix = vector<row>;

matrix mult(const matrix& a, const matrix& b, const int mod) {
  int n = a.size(), m = b.size(), l = b[0].size();
  matrix res(n, row(l));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      res[i][j] = 0;
      for (int k = 0; k < m; ++k) {
        res[i][j] += (a[i][k] * b[k][j]) % mod;
        res[i][j] %= mod;
      }
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, L;
  cin >> N >> L;

  int S, T;
  cin >> S >> T;

  matrix A(N, row(N, 0));
  matrix R(N, row(N, 0));

  for (int i = 0; i < N; ++i) {
    R[i][i] = 1;
    for (int j = 0; j < 4; ++j) {
      int x; cin >> x;
      A[i][x-1]++;
    }
  }

  while (L) {
    if (L & 1) R = mult(R, A, 1e4);
    A = mult(A, A, 1e4);
    L >>= 1;
  }

  cout << R[S-1][T-1] << "\n";

  return 0;
}
