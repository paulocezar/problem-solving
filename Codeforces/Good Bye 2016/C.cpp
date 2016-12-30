#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 18;
const int DIV1 = 1900;
const int INF = 1e9;

pair<int, int> contest[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> contest[i].first >> contest[i].second;
  }

  int change = contest[0].first;
  int min_x = -INF, max_x = INF;

  if (contest[0].second == 1) {
    min_x = DIV1;
  } else {
    max_x = DIV1 - 1;
  }

  for (int i = 1; i < n; ++i) {
    if (contest[i].second == 1) {
      min_x = max(min_x, DIV1 - change);
    } else {
      max_x = min(max_x, DIV1 - change - 1);
    }
    if (min_x > max_x) break;
    change += contest[i].first;
  }

  if (min_x > max_x) {
    cout << "Impossible\n";
  } else if (max_x == INF) {
    cout << "Infinity\n";
  } else {
    cout << max_x + change << "\n";
  }

  return 0;
}
