#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> v(10);

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    bool ronaldo = false, romario = false;
    for (int j = 0; j < 10; ++j) {
      if (j) cout << " ";
      int v; cin >> v;
      if (v == 17) romario = true;
      else if (v == 18) ronaldo = true;
      cout << v;
    }
    cout << "\n";
    if (romario && ronaldo) cout << "AMBOS\n\n";
    else if (romario) cout << "ROMARIO\n\n";
    else if (ronaldo) cout << "RONALDO\n\n";
    else cout << "NENHUM\n\n";
  }

  return 0;
}
