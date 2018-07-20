#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  using point = pair<int,int>;
  const static vector<int> deltas{-1, 0, 1};

  int t;
  cin >> t;
  while (t--)
  {
    int A, i, j;
    cin >> A;

    set<point> prepared;
    set<point> covered_cache;

    auto all_covered = [&prepared,&covered_cache](int x, int y)
    {
      if (covered_cache.count({x,y})) return true;

      for (const int dx : deltas)
        for (const int dy : deltas)
          if (!prepared.count({x+dx, y+dy})) return false;

      covered_cache.insert({x,y});
      return true;
    };

    vector<int> Xs;
    vector<int> Ys;

    for (int i = A == 200 ? 13 : 3; i >= 2; --i) Xs.push_back(i);
    for (int i = A == 200 ? 14 : 4; i >= 2; --i) Ys.push_back(i);

    bool done = false;
    do
    {
      for (const int x : Xs) for (const int y : Ys)
      {
        if (all_covered(x, y)) continue;
        cout << x << ' ' << y << endl;
        cin >> i >> j;
        prepared.insert({i, j});
        if ((i + j) == 0 || i == -1) { done = true; break; }
      }
    }
    while (!done);
  }

  return 0;
}
