#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int x, y, n;
  cin >> x >> y >> n;
  bool print = false;
  ostringstream out;

  for (int i = 1; i <= n; ++i) {
    int xx, yy; int64 t;
    cin >> xx >> yy >> t;
    int64 dist = (x-xx)*(x-xx) + (y-yy)*(y-yy); t *= t;
    if (dist < t) {
      if (print) out << " ";
      out << i;
      print = true;
    }
  }

  if (!print) out << "-1";
  cout << out.str() << "\n";


  return 0;
}
