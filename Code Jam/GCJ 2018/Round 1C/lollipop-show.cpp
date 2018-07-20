#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;

    vector<int> liked(N, 0);
    auto cmp = [&liked](int a, int b)
    {
      if (liked[a] != liked[b])
        return liked[a] < liked[b];
      return a < b;
    };

    set<int> available;
    for (int i = 0; i < N; ++i) available.insert(i);

    /*
    int M = N;
    int can_skip = M - ((90 * M + 99) / 100);
    int skipped = 0;
    */

    for (int customer = 0; customer < N; ++customer)
    {
      int D;
      cin >> D;

      /*
      if (D == 0)
      {
        --M;
        can_skip = M - ((90 * M + 99) / 100);
      }
      */

      vector<int> candidates;
      for (int i = 0; i < D; ++i)
      {
        int likes;
        cin >> likes;

        liked[likes]++;

        if (available.count(likes))
        {
          candidates.push_back(likes);
        }
      }

      if (candidates.empty())
      {
        cout << "-1" << endl;
        //if (D) ++skipped;
      }
      else
      {
        /*if (skipped < can_skip)
        {
          cout << "-1" << endl;
          ++skipped;
        }
        else
        {*/
          sort(candidates.begin(), candidates.end(), cmp);
          available.erase(candidates[0]);
          cout << candidates[0] << endl;
        //}
      }
    }
  }

  return 0;
}
