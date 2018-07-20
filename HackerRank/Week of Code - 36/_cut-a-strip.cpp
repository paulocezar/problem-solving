#include <bits/stdc++.h>

using namespace std;

const int MAXD = 1 << 9;

int current_sum[MAXD];
int running_sum[MAXD];
int running_sum_sz[MAXD];
int min_remove[MAXD];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> A(n, vector<int>(m));
  vector<vector<int>> At(m, vector<int>(n));
  int zeroes = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
      At[j][i] = A[i][j];
      zeroes += A[i][j] == 0;
    }
  }

  int res = 0;

  int twice = 2;
  while (twice--) {

    for (int i1 = 0; i1 < n; ++i1) {
      for (int j = 0; j < m; ++j) {
        min_remove[j] = std::numeric_limits<int>::max();
        current_sum[j] = 0;
        running_sum[j] = 0;
        running_sum_sz[j] = 0;
      }

      for (int i2 = i1; i2 < n; ++i2) {
        for (int j = 0; j < m; ++j) {
          current_sum[j] += A[i2][j];
          running_sum[j] += A[i2][j]; running_sum_sz[j]++;

          if (running_sum_sz[j] > k) {
            do {
              running_sum_sz[j]--;
              running_sum[j] -= A[i2 - running_sum_sz[j]][j];
            } while (running_sum_sz[j] && (running_sum[j] >= (running_sum[j] - A[i2 - running_sum_sz[j] + 1][j])));
          }

          if (running_sum_sz[j])
            min_remove[j] = min(min_remove[j], running_sum[j]);
          if (A[i2][j] == 0) min_remove[j] = min(min_remove[j], 0);

          if (running_sum[j] >= 0) running_sum[j] = 0, running_sum_sz[j] = 0;
        }

        int normal_sum = current_sum[0];
        int used_cols = 1;
        int stripped_sum = current_sum[0] - min_remove[0];

        res = max(res, stripped_sum);
        if (m > 1 || i1 > 0 || i2 < (n-1))
          res = max(res, normal_sum);

        if (normal_sum <= 0) normal_sum = 0, used_cols = 0;
        if (stripped_sum < 0) stripped_sum = 0;

        for (int j2 = 1; j2 < m; ++j2) {
          stripped_sum += current_sum[j2];
          if ((normal_sum + current_sum[j2] - min_remove[j2]) >= stripped_sum) {
            stripped_sum = (normal_sum + current_sum[j2] - min_remove[j2]);
          }

          normal_sum += current_sum[j2]; ++used_cols;

          res = max(res, stripped_sum);
          if (i1 != 0 || i2 != (n-1) || used_cols != m || zeroes)
            res = max(res, normal_sum);

          if (normal_sum <= 0) normal_sum = 0, used_cols = 0;
          if (stripped_sum < 0) stripped_sum = 0;
        }
      }
    }
    swap(A, At);
    swap(n, m);
  }
  cout << res << "\n";

  return 0;
}
