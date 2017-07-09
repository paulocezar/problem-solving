#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;

    vector<int> j(N), m(N);
    for (int &v : j) cin >> v;
    for (int &v : m) cin >> v;

    sort(j.begin(), j.end());
    sort(m.begin(), m.end());

    int mp = 0, ties = 0;
    for (int mm = 0; mm < N; ++mm) {
      for (int jj = N-1; jj >= 0; --jj) {
        if (m[mm] > j[jj]) {
          j[jj] = 2e9;
          m[mm] = 2e9;
          mp++;
          break;
        }
      }
    }

    for (int mm = 0; mm < N; ++mm) {
      if (m[mm] > 1337) continue;
      for (int jj = 0; jj < N; ++jj) {
        if (m[mm] == j[jj]) {
          ties++;
          m[mm] = 2e9;
          j[jj] = 2e9;
          break;
        }
      }
    }

    int jp = N - mp - ties;

    cout << "Caso " << tc << ": ";
    if (mp > jp) {
      cout << "Maria";
    } else if (jp > mp) {
      cout << "Joao";
    } else {
      cout << "Empate";
    }
    cout << "\n";

  }


  return 0;
}
