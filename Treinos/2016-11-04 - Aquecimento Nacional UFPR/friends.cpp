#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int pa[MAXN], rk[MAXN];
int sz[MAXN];
const double pi = acos(-1.0);

int find(int x) {
    int ax, px = x;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rk[y] > rk[x]) swap(x,y);
    pa[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
    sz[x] += sz[y];
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    map<string, int> hash;
    int F;
    cin >> F;
    while (F--) {
      string n1, n2;
      cin >> n1 >> n2;
      if (!hash.count(n1)) {
        int ax = hash.size();
        hash[n1] = ax;
        pa[ax] = ax; rk[ax] = 0; sz[ax] = 1;
      }
      if (!hash.count(n2)) {
        int ax = hash.size();
        hash[n2] = ax;
        pa[ax] = ax; rk[ax] = 0; sz[ax] = 1;
      }
      fUnion(hash[n1], hash[n2]);
      cout << sz[find(hash[n1])] << "\n";
    }
  }

  return 0;
}
