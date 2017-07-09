#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;
int p[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int n, r, c; char dot;
    cin >> n >> r >> dot >> c;
    int has = 100*r + c;
    for (int i = 0; i < n; ++i) {
      cin >> r >> dot >> c;
      p[i] = 100*r + c;
    }
    sort(p, p+n);
    int spent = 0;
    int bought = 0;
    while (bought < n && ((spent + p[bought]) <= has)) {
      spent += p[bought++];
    }
    cout << "Caso " << tc << ": " << bought << " " << (spent/100) << "." << setw(2) << setfill('0') << (spent % 100) << "\n";
  }

  return 0;
}
