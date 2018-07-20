#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int kase = 1; kase <= T; ++kase)
  {
    int64_t D;
    string P;
    cin >> D >> P;

    int64_t strength = 1;
    int64_t total_damage = 0;
    priority_queue<int64_t> damages;

    for (char c : P)
    {
      if (c == 'C') strength *= 2;
      else { damages.push(strength); total_damage += strength; }
    }

    int hacks = 0;
    while (total_damage > D && damages.top() > 1)
    {
      ++hacks;
      auto top_damage = damages.top(); damages.pop();
      top_damage /= 2;
      total_damage -= top_damage;
      damages.push(top_damage);
    }

    cout << "Case #" << kase << ": ";
    if (total_damage <= D) cout << hacks << "\n";
    else cout << "IMPOSSIBLE\n";

  }



  return 0;
}
