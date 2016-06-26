#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int rating[1<<17], mn[1<<17], id[1<<17], grant[1<<17];


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> rating[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> mn[i];
    id[i] = i;
  }

  sort(id, id+N, [](int i, int j) {
    if (rating[i] != rating[j]) return rating[i] < rating[j];
    return mn[i] < mn[j];
  });

  int64 ans = 0LL;

  for (int i = 0; i < N; ++i) {
    int must_grant = mn[id[i]];
    int lo = max(0, id[i] - 10);
    int hi = min(id[i]+10, N-1);
    while (lo <= hi) {
      if (rating[lo] != rating[id[i]]) must_grant = max(must_grant, grant[lo]+1);
      lo++;
    }
    grant[id[i]] = must_grant;
    ans += must_grant;
  }

  cout << ans << "\n";

  return 0;
}
