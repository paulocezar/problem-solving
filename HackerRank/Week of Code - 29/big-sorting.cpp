#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 18;

string unsorted[MAXN];
int ord[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> unsorted[i];
    ord[i] = i;
  }

  sort(ord, ord+n, [&unsorted](int a, int b) {
    int sa = unsorted[a].size();
    int sb = unsorted[b].size();
    if (sa != sb) return sa < sb;
    for (int i = 0; i < sa; ++i) {
      if (unsorted[a][i] != unsorted[b][i]) return unsorted[a][i] < unsorted[b][i];
    }
    return false;
  });

  for (int i = 0; i < n; ++i) {
    cout << unsorted[ord[i]] << "\n";
  }

  return 0;
}
