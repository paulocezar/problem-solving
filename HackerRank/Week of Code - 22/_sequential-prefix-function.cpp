#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int p[1<<18];
int s[1<<18];
int opx[1<<18];
char op[1<<18];

void scanint(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scanop(char &op) {
   for (op = getchar_unlocked(); op!='+' && op != '-'; op = getchar_unlocked());
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n = 0, q;

  scanint(q);
  for (int i = 0; i < q; ++i) {
      scanop(op[i]);
      if (op[i] == '+') scanint(opx[i]);
  }

  ostringstream buff;
  p[0] = 0, p[1] = 0;
  for (int i = 0; i < q; ++i) {
    if (op[i] == '+') {
      s[n++] = opx[i];
      if (n > 1) {
        int j = p[n-1];
        while (s[n-1] != s[j]) {
            if (j == 0) { j = -1; break; }
            j = p[j];
        }
        p[n] = ++j;
      }
    } else {
      n--;
    }
    buff << p[n] << "\n";
  }
  cout << buff.str();
  return 0;
}
