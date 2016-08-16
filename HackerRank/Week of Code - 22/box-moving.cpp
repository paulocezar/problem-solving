#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

int64 sx[MAXN], sy[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int64 sumx = 0LL, sumy = 0LL;
  for (int i = 0; i < N; ++i) { cin >> sx[i]; sumx += sx[i]; }
  for (int i = 0; i < N; ++i) { cin >> sy[i]; sumy += sy[i]; }

  if (sumx == sumy) {
    sort(sx, sx+N);
    sort(sy, sy+N);
    int64 diff = 0LL;
    for (int i = 0; i < N; ++i) diff += abs(sx[i] - sy[i]);
    cout << (diff / 2LL) << "\n";
  } else {
    cout << "-1\n";
  }

  return 0;
}
