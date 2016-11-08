#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;

char cached[2][256][256][256];
int cache[2][256][256][256];

int count(int prv, int rem, int need, int opn) {
  if (!rem) return ((!opn && !need) ? 1 : 0);
  int &r = cache[prv][rem][need][opn];
  char &c = cached[prv][rem][need][opn];
  if (c) return r;
  c = 1;
  r = count(0, rem-1, max(0, need - prv), opn + 1);
  if (opn) {
    r += count(1, rem-1, max(0, need - 1 + prv), opn - 1);
    if (r >= MOD) r -= MOD;
  }
  return r;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    cout << count(0, n-1, k, 1) << "\n";
  }


  return 0;
}
