#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector< pair<int, string> > r = {{0, "Otavio"}, {0, "Bruno"}, {0, "Ian"}};
  for (auto &e : r) {
    double val; cin >> val;
    e.first = 1000 * val;
  }
  sort(r.begin(), r.end());

  if (r[0].first == r[1].first) cout << "Empate\n";
  else cout << r[0].second << "\n";

  return 0;
}
