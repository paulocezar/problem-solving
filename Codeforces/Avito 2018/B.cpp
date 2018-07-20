#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  unordered_map<int, int> best_use;

  for (int i = 0; i < n; ++i)
  {
    int a, x;
    cin >> a >> x;
    best_use[a] = x;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i)
  {
    int b, y;
    cin >> b >> y;
    if (best_use[b] < y) best_use[b] = y;
  }

  int64_t res = 0;
  for (const auto& entry : best_use)
  {
    res += entry.second;
  }

  cout << res << "\n";

  return 0;
}
