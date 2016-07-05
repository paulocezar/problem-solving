#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const unsigned int mod = 1000000007;
unsigned int ways[100002][11];

vector<int> coins;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  coins.resize(N);

  for (int &v : coins) { cin >> v; }
  sort(coins.begin(), coins.end());

  int64 L, R;
  cin >> L >> R;

  unsigned int acmL = 0, acmR = 0;

  for (int i = 1; i <= N; ++i) ways[0][i] = 1;

  int i = 0;
  for (int64 val = 1LL; val <= R; ++val) {
    i++;

    if (i > coins[N-1]) i = 0;

    for (int j = 0; j < N; ++j) {
      int pi = i - coins[j];
      if (pi < 0) pi += coins[N-1] + 1;
      ways[i][j+1] = ways[i][j] + ways[pi][j+1];
      ways[i][j+1] -= mod * ((ways[i][j+1] >> 30) & 3);
    }

    if (val < L) {
      acmL += ways[i][N];
      acmL -= mod * ((acmL >> 30) & 3);
    }
    acmR += ways[i][N];
    acmR -= mod * ((acmR >> 30) & 3);
  }

  acmR %= mod; acmL %= mod;
  acmR -= acmL;
  acmR += mod; acmR %= mod;
  cout << acmR << "\n";

  return 0;
}
