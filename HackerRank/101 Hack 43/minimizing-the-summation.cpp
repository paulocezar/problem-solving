#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int a[MAXN];

int64 sqsm[MAXN];
int64 sm[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 0; i < n; ++i) {
    sqsm[i] = i ? sqsm[i-1] : 0LL;
    sm[i] = i ? sm[i-1] : 0LL;
    sm[i] += a[i];
    sqsm[i] += a[i] * a[i];
  }

  int64 res = 0LL;
  for (int i = 0; i + k <= n; ++i) {
    int64 axsq = sqsm[i+k-1] - (i ? sqsm[i-1] : 0LL);
    int64 axsm = sm[i+k-1] - (i ? sm[i-1] : 0LL);
    int64 cur = 2LL * k * axsq - 2LL * axsm * axsm;
    if (i == 0 || cur < res) res = cur;
  }
  cout << res << "\n";

  return 0;
}
