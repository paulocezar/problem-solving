#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  auto check = [&s] (int i, int j)
  {
    while (i <= j)
    {
      if (s[i] != s[j]) return true;
      ++i;
      --j;
    }
    return false;
  };

  const int len = s.size();
  int res = len;
  bool found = false;
  while (res && !found)
  {
    for (int i = 0; i+res <= len; ++i)
    {
      if (check(i, i + res - 1))
      {
        found = true;
        break;
      }
    }
    if (!found) --res;
  }

  cout << res << "\n";

  return 0;
}
