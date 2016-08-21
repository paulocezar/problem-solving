#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MINCENTS = 200, MAXCENTS = 500;
string G, GA, GP;

bool possible(int v, string &s) {
  ostringstream out;
  out << v;
  for (int i = 0; i < 3; ++i) {
    if (out.str()[i] != s[i] && s[i] != '-') return false;
  }
  return true;
}


void change(int v, string &s) {
  ostringstream out;
  out << v;
  s = out.str();
}

void fix() {
  for (int g = MINCENTS; g <= MAXCENTS; ++g) {
    if (!possible(g, G)) continue;
    for (int ga = g+1; ga <= MAXCENTS; ++ga) {
      if (!possible(ga, GA)) continue;
      for (int gp = ga+1; gp <= MAXCENTS; ++gp) {
        if (!possible(gp, GP)) continue;
        change(g, G);
        change(ga, GA);
        change(gp, GP);
        return;
      }
    }
  }
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Posto de Gasolina #" << t << ":\n";
    cin >> G >> GA >> GP;
    cout << "   Entrada: " << G << " " << GA << " " << GP << "\n";
    fix();
    cout << "   Saida: " << G << " " << GA << " " << GP << "\n";
    cout << "\n";
  }


  return 0;
}
