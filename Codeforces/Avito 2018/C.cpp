#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> degree(n+1, 0);

  for (int i = 1; i < n; ++i)
  {
    int u, v;
    cin >> u >> v;
    ++degree[u];
    ++degree[v];
  }

  int high_degree = 0;
  int leafs = 0;

  for (int i = 1; i <= n; ++i)
  {
    if (degree[i] >= 3) high_degree = high_degree ? -1 : i;
    else if (degree[i] == 1) ++leafs;
  }

  if (high_degree == -1)
  {
    cout << "No\n";
  }
  else
  {
    cout << "Yes\n";

    if (high_degree)
    {
      cout << leafs << "\n";
      for (int i = 1; i <= n; ++i)
      {
        if (degree[i] == 1)
        {
          cout << high_degree << " " << i << "\n";
        }
      }
    }
    else
    {
      assert(leafs == 2);
      int leaf1 = 0, leaf2 = 0;
      for (int i = 1; i <= n; ++i)
      {
        if (degree[i] == 1) { leaf2 = leaf1; leaf1 = i; }
      }
      cout << "1\n" << leaf1 << " " << leaf2 << "\n";
    }
  }

  return 0;
}
