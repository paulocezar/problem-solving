#include <bits/stdc++.h>

using namespace std;

const int MAXN = 64;

array<int64_t, MAXN> a;

char cache[MAXN][MAXN];
int last_cached[MAXN][MAXN], cached_now;

int64_t wanted;
bool can_do(int elements, int shelves)
{
  auto& res = cache[elements][shelves];

  if (last_cached[elements][shelves] == cached_now)
    return res;

  last_cached[elements][shelves] = cached_now;
  res = 0;

  if (shelves == 1)
  {
    int64_t cur = 0;
    while (elements)
    {
      --elements;
      cur += a[elements];
    }

    res = (cur & wanted) == wanted;
  }
  else
  {
    int64_t cur = 0;
    for (int use = 1; !res && (elements-use >= shelves-1); ++use)
    {
      cur += a[elements-use];
      res = ((cur & wanted) == wanted) && can_do(elements-use, shelves-1);
    }
  }

  return res;
}

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  wanted = 0;
  int64_t cur_bit = 1LL << 56;
  while (cur_bit)
  {
    wanted |= cur_bit;
    ++cached_now;
    auto ret = can_do(n, k);
    if (!ret) wanted ^= cur_bit;
    cur_bit >>= 1;
  }

  cout << wanted << "\n";

  return 0;
}
