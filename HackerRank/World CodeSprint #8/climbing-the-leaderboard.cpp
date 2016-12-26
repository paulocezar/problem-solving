#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &v : a) cin >> v;
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  int m;
  cin >> m;
  while (m--) {
    int score; cin >> score;
    int lw = upper_bound(a.begin(), a.end(), score) - a.begin();
    cout << a.size() - lw + 1 << "\n";
  }

  return 0;
}
