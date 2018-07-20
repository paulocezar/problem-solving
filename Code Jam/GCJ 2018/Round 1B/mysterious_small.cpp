#include <bits/stdc++.h>

using namespace std;

using Sign = pair<int,int>;

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int kase = 1; kase <= T; ++kase)
  {
    int S;
    cin >> S;

    vector<Sign> signs(S);
    for (auto& sign : signs)
    {
      int D, A, B;
      cin >> D >> A >> B;
      sign = {D + A, D - B};
    }

    int lo = 1, hi = S, largest_sets = 0;
    while (lo <= hi)
    {
      int mid = (lo + hi) / 2;
      int valid_sets = 0;
      for (int i = 0; i + mid <= S; ++i)
      {
        unordered_set<int> bad_n;
        unordered_set<int> bad_m;
        for (int j = i; j < i+mid; ++j)
        {
          if (signs[j].first != signs[i].first)
          {
            bad_n.insert(signs[j].second);
          }

          if (signs[j].second != signs[i].second)
          {
            bad_m.insert(signs[j].first);
          }
        }

        if (bad_n.size() <= 1 || bad_m.size() <= 1)
        {
          ++valid_sets;
        }
      }

      if (valid_sets)
      {
        lo = mid + 1;
        largest_sets = valid_sets;
      }
      else
      {
        hi = mid - 1;
      }
    }


    cout << "Case #" << kase << ": " << hi << " " << largest_sets << "\n";
  }


  return 0;
}
