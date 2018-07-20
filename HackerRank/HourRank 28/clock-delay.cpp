#include <bits/stdc++.h>

using namespace std;



int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;
  while (q--)
  {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    h1 += k;
    cout << (h1*60 + m1) - (h2*60 + m2) << "\n";
  }


  return 0;
}
