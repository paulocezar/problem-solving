#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int px[MAXN], py[MAXN];
int xa[MAXN], ya[MAXN], xb[MAXN], yb[MAXN];
int fences[MAXN], rfences[MAXN];

bool inside(int fence, int pt) {
  return (xa[fence] <= px[pt] && px[pt] <= xb[fence]) &&
         (ya[fence] <= py[pt] && py[pt] <= yb[fence]);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> px[i] >> py[i];
  }

  string cmd;
  int pa, pb, nf = 0;

  for (int qq = 0; qq < q; ++qq) {
    cin >> cmd;
    switch (cmd[0]) {
      case 'a':
        rfences[qq] = nf;
        fences[nf++] = qq;
        cin >> xa[qq] >> ya[qq] >> xb[qq] >> yb[qq];
        break;
      case 'd':
        cin >> pa; pa--;
        rfences[fences[nf-1]] = rfences[pa];
        swap(fences[rfences[pa]], fences[--nf]);
        break;
      case 'q':
        cin >> pa >> pb; pa--, pb--;
        bool ok = true;
        for (int i = 0; i < nf; ++i) {
          if (inside(fences[i], pa) != inside(fences[i], pb)) {
            ok = false;
            break;
          }
        }
        cout << (ok ? "YES" : "NO") << "\n";
        break;
    }
  }

  return 0;
}
