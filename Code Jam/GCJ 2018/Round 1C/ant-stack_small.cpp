#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int w[MAXN+1];

int cache[128][6010];
int last_cached[128][6010], cached_now;

int solve(int at, int mwg)
{
  if (at == 0)
    return w[at] <= mwg ? 1 : 0;

  int& res = cache[at][mwg];
  int& lc = last_cached[at][mwg];
  if (lc == cached_now)
    return res;
  lc = cached_now;

  res = solve(at-1, mwg);
  if (w[at] <= mwg)
    res = max(res, 1 + solve(at-1, min(6*w[at], mwg - w[at])));

  return res;
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int kase = 1; kase <= T; ++kase)
  {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
      cin >> w[i];
    }

    int res = 1;
    ++cached_now;

    for (int i = 1; i < N; ++i)
    {
      res = max(res, 1 + solve(i-1, 6 * w[i]));
    }

    cout << "Case #" << kase << ": " << res << "\n";
  }

  return 0;
}
