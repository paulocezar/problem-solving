#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;
const int MAXM = 1<<18;

int64 cnt[MAXM];
pair<int,int> edge[MAXM];

int pa[MAXN], rk[MAXN];

vector<int> gr[MAXN];

int find(int x) {
    int px = x, ax;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rk[y] > rk[x]) swap(x,y);
    if (rk[x] == rk[y]) rk[x]++;
    pa[y] = x;
    return true;
}

int N, M;
int do_it(int u, int pa = -1) {
  int res = 1;
  for (int &e : gr[u]) {
    int v = edge[e].first + edge[e].second - u;
    if (v == pa) continue;
    int sz = do_it(v, u);
    cnt[e] += int64(sz) * int64(N-sz);
    res += sz;
  }
  return res;
}

bool print_it(int bit, int64 carry = 0LL) {
  if ((bit >= M) && (carry <= 0LL)) return false;

  int64 cur = ((bit < M) ? cnt[bit] : 0LL) + carry;
  bool r = print_it(bit+1, cur >> 1);

  if (r) {
    cout << (cur&1LL);
    return true;
  } else if ((bit == 0) || (cur&1LL)) {
    cout << (cur&1LL);
    return true;
  }
  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int ai, bi, ci; cin >> ai >> bi >> ci;
    edge[ci] = make_pair(ai, bi);
  }

  for (int i = 1; i <= N; ++i) {
    pa[i] = i, rk[i] = 0;
  }

  for (int i = 0; i < M; ++i) {
    if (fUnion(edge[i].first, edge[i].second)) {
      gr[edge[i].first].push_back(i);
      gr[edge[i].second].push_back(i);
    }
  }

  do_it(1);
  print_it(0);
  cout << "\n";

  return 0;
}
