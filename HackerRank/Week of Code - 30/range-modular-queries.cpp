#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 16;
const int MAXQ = 1 << 16;
const int MAXVAL = 1 << 16;

int a[MAXN];
int cnt[MAXVAL];
int ans[MAXQ];

struct query {
  int id, left, right, x, y;
} Q[MAXQ];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    cin >> Q[i].left >> Q[i].right >> Q[i].x >> Q[i].y;
    Q[i].id = i;
  }

  int SQ = (int)sqrt(double(n));
  sort(Q, Q+q, [&SQ](const query& a, const query& b) -> bool {
    int ba = (a.left) / SQ;
    int bb = (b.left) / SQ;
    if (ba != bb) return ba < bb;
    return a.right < b.right;
  });

  int curL = Q[0].left, curR = Q[0].left;
  cnt[a[curL]] = 1;

  for (int i = 0; i < q; ++i) {

    while (Q[i].left < curL) cnt[a[--curL]]++;
    while (Q[i].left > curL) cnt[a[curL++]]--;
    while (Q[i].right > curR) cnt[a[++curR]]++;
    while (Q[i].right < curR) cnt[a[curR--]]--;

    int cur = 0, a = 0;
    if (Q[i].x == 1) cur = curR - curL + 1;
    else while ((a*Q[i].x + Q[i].y) < MAXVAL) {
      cur += cnt[a*Q[i].x + Q[i].y];
      a++;
    }
    ans[Q[i].id] = cur;
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
