#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  set<string> s;
  int n;
  cin >> n;
  while (n--) {
    string nm; cin >> nm;
    s.insert(nm);
  }
  cout << "Falta(m) " << (151 - s.size()) << " pomekon(s).\n";

  return 0;
}
