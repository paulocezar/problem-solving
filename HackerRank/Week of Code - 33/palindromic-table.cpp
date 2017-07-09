#include <bits/stdc++.h>

using namespace std;

int zero_sum[1 << 17];
int seen_at[1 << 10];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> table(n, vector<int>(m));
  vector<vector<int>> zeroes(n, vector<int>(m));
  vector<vector<int>> mask(n, vector<int>(m));

  int res = 1;
  int xa = 0, ya = 0, xb = 0, yb = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> table[i][j];
    }
  }

  if (n <= m) {
    for (int y = 0; y < m; ++y) {
      zeroes[0][y]  = (table[0][y] ? 0 : 1);
      mask[0][y] = (1 << table[0][y]);
      for (int x = 1; x < n; ++x) {
        zeroes[x][y] = zeroes[x-1][y] + (table[x][y] ? 0 : 1);
        mask[x][y] = mask[x-1][y] ^ (1 << table[x][y]);
      }
    }

    for (int x1 = 0; x1 < n; ++x1) {
      for (int x2 = x1; x2 < n; ++x2) {
        if ((m * (x2-x1+1)) <= res) continue;

        memset(seen_at, 0, sizeof(seen_at));
        seen_at[0] = 1;
        zero_sum[0] = 0;
        int cur = 0;
        for (int y2 = 0; y2 < m; ++y2) {
          zero_sum[y2+1] = zero_sum[y2] + (zeroes[x2][y2] - (x1 ? zeroes[x1-1][y2] : 0));
          cur ^= (mask[x2][y2] ^ (x1 ? mask[x1-1][y2] : 0));
          for (int i = 0; i <= 10; ++i) {
            int complement = ((cur ^ (1<<i)) & 1023);
            if (seen_at[complement]) {
              int y1 = seen_at[complement] - 1;
              int total = (y2 - y1 + 1) * (x2 - x1 + 1);
              int nonzeroes = total - zero_sum[y2+1] + zero_sum[y1];
              if ((total > res) && (nonzeroes >= 2)) {
                res = total;
                xa = x1, ya = y1, xb = x2, yb = y2;
              }
            }
          }
          if (!seen_at[cur]) seen_at[cur] = y2 + 2;
        }
      }
    }
  } else {
    for (int x = 0; x < n; ++x) {
      zeroes[x][0]  = (table[x][0] ? 0 : 1);
      mask[x][0] = 1 << table[x][0];
      for (int y = 1; y < m; ++y) {
        zeroes[x][y] = zeroes[x][y-1] + (table[x][y] ? 0 : 1);
        mask[x][y] = mask[x][y-1] ^ (1 << table[x][y]);
      }
    }

    for (int y1 = 0; y1 < m; ++y1) {
      for (int y2 = y1; y2 < m; ++y2) {
        if ((n * (y2-y1+1)) <= res) continue;

        memset(seen_at, 0, sizeof(seen_at));
        seen_at[0] = 1;
        zero_sum[0] = 0;
        int cur = 0;
        for (int x2 = 0; x2 < n; ++x2) {
          zero_sum[x2+1] = zero_sum[x2] + (zeroes[x2][y2] - (y1 ? zeroes[x2][y1-1] : 0));
          cur ^= (mask[x2][y2] ^ (y1 ? mask[x2][y1-1] : 0));
          for (int i = 0; i <= 10; ++i) {
            int complement = ((cur ^ (1<<i)) & 1023);
            if (seen_at[complement]) {
              int x1 = seen_at[complement] - 1;
              int total = (y2 - y1 + 1) * (x2 - x1 + 1);
              int nonzeroes = total - zero_sum[x2+1] + zero_sum[x1];
              if ((total > res) && (nonzeroes >= 2)) {
                res = total;
                xa = x1, ya = y1, xb = x2, yb = y2;
              }
            }
          }
          if (!seen_at[cur]) seen_at[cur] = x2 + 2;
        }
      }
    }
  }

  cout << res << "\n";
  cout << xa << " " << ya << " " << xb << " " << yb << "\n";

  return 0;
}
