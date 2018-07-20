#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

array<int, MAXN+1> C;

int cache[256][256];
char last_cached[256][256], cached_now;

double total;

int solve(int lang, int unassigned)
{
  if (lang < 256 && unassigned < 256 && last_cached[lang][unassigned] == cached_now)
    return cache[lang][unassigned];

  int ret = 0;
  int cur = lang ? C[lang-1] : 0;
  for (int add = 0; add <= unassigned; ++add)
  {
    int val = static_cast<int>(0.5 + 100.0 * double(cur+add) / total);
    ret = max(ret, val + ((cur+add) ? solve(max(0, lang-1), unassigned-add) : 0));
  }

  if (lang < 256 && unassigned < 256)
  {
    last_cached[lang][unassigned] = cached_now;
    cache[lang][unassigned] = ret;
  }
  return ret;
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int kase = 1; kase <= T; ++kase)
  {
    int N, L;
    cin >> N >> L;

    int unassigned = N;
    for (int i = 0; i < L; ++i)
    {
      cin >> C[i];
      unassigned -= C[i];
    }

    total = N;
    ++cached_now;
    cout << "Case #" << kase << ": "  << solve(L, unassigned) << "\n";

  }

  return 0;
}
