#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<string> A(n);
  for (auto& s : A) cin >> s;

  vector<int> single_switch(m, 0);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (A[i][j] == '1')
      {
        if (single_switch[j] == 0) single_switch[j] = i+1;
        else single_switch[j] = -1;
      }
    }
  }

  unordered_set<int> required;
  for (auto v : single_switch)
  {
    if (v != -1)
      required.insert(v);
  }

  if (static_cast<int>(required.size()) == n) cout << "NO\n";
  else cout << "YES\n";

  return 0;
}
