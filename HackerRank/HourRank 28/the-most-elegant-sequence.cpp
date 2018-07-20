#include <bits/stdc++.h>

using namespace std;

// const int MAXN = 19; // runtime error?
const int MAXN = 20;

int B[MAXN+1];
int digit_cnt[MAXN][10];

int64_t dp[MAXN + 1][1 << MAXN];
char cached[MAXN + 1][1 << MAXN];

int64_t doit(int mask, int prev)
{
  int64_t& res = dp[prev][mask];
  char& in_cache = cached[prev][mask];
  if (in_cache) return res;
  in_cache = 1;
  res = 0;

  for (int i = 0, bi = 1; bi <= mask; ++i, bi <<= 1)
  {
    if (!(mask & bi)) continue;
    res = max(res, (B[prev]^B[i]) + doit(mask ^ bi, i));
  }

  return res;
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);


  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i)
    cin >> B[i];
  B[n] = 0;

  for (int i = 0; i < n; ++i)
  {
    string si;
    cin >> si;
    for (char c : si)
      ++digit_cnt[i][c - '0'];
  }

  int64_t res = 0;

  int mask = (1 << n) - 1;
  while (mask)
  {
    array<int, 10> mask_cnt{0};
    for (int i = 0, bi = 1; i < n; ++i, bi <<= 1)
    {
      if (mask & bi)
      {
        for (int j = 0; j < 10; ++j) mask_cnt[j] += digit_cnt[i][j];
      }
    }

    const bool possible = all_of(mask_cnt.begin(), mask_cnt.end(), [&q](const int& v) { return v <= q; });

    if (possible)
    {
      res = max(res, doit(mask, n));
    }

    --mask;
  }

  cout << res << "\n";

  return 0;
}
