#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

char cached[11][601][1024];
int cache[11][601][1024];

int grundy[601];

int count(int n, int m, int xr) {
  if (n == 0 && m == 0) return (xr ? 1 : 0);
  if (n == 0 || m == 0) return 0;

  int &res = cache[m][n][xr];
  if (cached[m][n][xr]) return res;
  cached[m][n][xr] = 1;
  res = 0;
  for (int put = 1; put <= (n-m+1); ++put) {
    res += count(n-put, m-1, xr ^ grundy[put]);
    if (res >= mod) res -= mod;
  }
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  switch (K) {
    case 2:
      for (int i = 1; i <= N; ++i) grundy[i] = 1 - (i&1);
      break;
    case 3:
      for (int i = 0; i <= N; ++i) {
        set<int> seen;
        for (int j = 1; j < i; ++j) {
          seen.insert(grundy[j] ^ grundy[i-j]);
          for (int k = j; (j+k) < i; ++k) {
            seen.insert(grundy[j] ^ grundy[k] ^ grundy[i-j-k]);
          }
        }

        while (seen.count(grundy[i])) grundy[i]++;
      }
      break;
    default:
      for (int i = 2; i <= N; ++i) grundy[i] = i-1;
      break;
  }

  cout << count(N, M, 0) << "\n";

  return 0;
}
