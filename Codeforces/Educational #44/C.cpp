#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, l;
  cin >> n >> k >> l;

  vector<int> staves(n*k);
  for (int&v : staves) cin >> v;
  sort(staves.begin(), staves.end());

  auto hi = upper_bound(staves.begin(), staves.end(), staves[0] + l);

  int candidates = hi - staves.begin();
  int64_t res{0};

  int remaining = n;
  int geq = n*k - candidates;

  while (remaining)
  {
    if (hi == staves.begin()) break;
    --hi;

    if ((geq+1) >= k)
    {
      res += *hi;
      geq -= (k-1);
      --remaining;
    }
    else
    {
      geq++;
    }
  }

  if (remaining) res = 0;

  cout << res << "\n";

  return 0;
}
