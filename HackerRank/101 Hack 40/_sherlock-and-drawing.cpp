#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 edges[64];
int64 r1, c1, r2, c2;
int64 Ns, Es;

inline bool contained(const int64 &r, const int64 &c) {
  return (r1 <= r) && (r <= r2) && (c1 <= c) && (c <= c2);
}

void doit(int h, int64 r, int64 c, char ed = 0, int64 sn = 0) {

  if (ed == 1) {
    if (contained(r, c)) Es++;

    if ((sn+1) == edges[h]) doit(h-1, r+1, c-1, 0);
    else doit(h, r+1, c-1, ed, sn+1);

  } else if (ed == 2) {
    if (contained(r, c)) Es++;

    if ((sn+1) == edges[h]) doit(h-1, r+1, c+1, 0);
    else doit(h, r+1, c+1, ed, sn+1);

  } else {
    if (contained(r, c)) Ns++;

    if (h) doit(h, r+1, c-1, 1);
    if (h) doit(h, r+1, c+1, 2);
  }
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int h, q;
    int64 rr, rc;
    cin >> h >> rr >> rc >> q;

    edges[1] = 1;
    edges[2] = 2;
    for (int i = 3; i <= h; ++i) {
      edges[i] = 2LL * edges[i-1] + 1LL;
    }

    ostringstream out;
    while (q--) {
      cin >> r1 >> c1 >> r2 >> c2;
      Ns = 0, Es = 0;
      doit(h, rr, rc);
      out << Ns << " " << Es << "\n";
    }
    cout << out.str();

    return 0;
}
