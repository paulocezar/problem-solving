#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 18;

int64 improve[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int64 for_sure = 0LL;

  for (int i = 0; i < n; ++i) {
    int64 p, d;
    cin >> p >> d;
    improve[i] = p + d;
    for_sure -= d;
  }

  sort(improve, improve+n);
  for (int i = max(n-k, 0); i < n; ++i) {
    for_sure += improve[i];
  }

  cout << max(for_sure, 0LL) << "\n";


  return 0;
}
