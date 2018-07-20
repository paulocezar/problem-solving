#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> pieces(n / 2);
  for (int &v : pieces) cin >> v;
  sort(pieces.begin(), pieces.end());

  auto required_moves = [](auto from, auto to, int pos, int inc)
  {
    int res = 0;
    while (from != to)
    {
      res += abs(*from - pos);
      pos += inc;
      ++from;
    }
    return res;
  };

  int moves_even = required_moves(pieces.crbegin(), pieces.crend(), n, -2);
  int moves_odd = required_moves(pieces.cbegin(), pieces.cend(), 1, 2);

  cout << min(moves_even, moves_odd) << "\n";

  return 0;
}
