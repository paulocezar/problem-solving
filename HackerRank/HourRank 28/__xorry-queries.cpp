#include <bits/stdc++.h>

using namespace std;

const int LGMN = 17;
const int MAXN = (1 << LGMN);

/*
int64_t segt[1 << (LGMN + 1)];
int lazy[1 << (LGMN + 1)];
*/

int a[MAXN];
int P[MAXN];

/* didn't get there.. should have stored counts of each bit
void build(int node, int lo, int hi)
{
  lazy[node] = 0;

  if (lo == hi)
  {
    segt[node] = P[lo];
  }
  else
  {
    const int mid = (lo + hi) >> 1;
    const int ls = (node << 1) + 1;
    const int rs = ls + 1;

    build(ls, lo, mid);
    build(rs, mid+1, hi);

    segt[node] = segt[ls] + segt[rs];
  }
}

void push(int node, bool is_leaf)
{
  if (!lazy[node]) return;



}

int from, to, update_with;
void update(int node, int lo, int hi)
{
  push(node, lo == hi);
  if (hi < from || lo > to) return;

  if (from <= lo && hi <= to)
  {
    // ...
  }
  else
  {
    const int mid = (lo + hi) >> 1;
    const int ls = (node << 1) + 1;
    const int rs = ls + 1;

    update(ls, lo, mid);
    update(rs, mid+1, hi);

    segt[node] = segt[ls] + segt[rs];
  }
}

int64_t query(int node, int lo, int hi)
{
  push(node, lo == hi);
  if (hi < from || lo > to) return 0;

  if (from <= lo && hi <= to)
  {
    return segt[node];
  }
  else
  {
    const int mid = (lo + hi) >> 1;
    const int ls = (node << 1) + 1;
    const int rs = ls + 1;

    return query(ls, lo, mid) + query(rs, mid+1, hi);
  }
}
*/

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, p;
  cin >> n >> m >> p;

  for (int i = 1; i <= n; ++i) cin >> a[i];

  a[n+1] = 0;
  for (int i = n; i > 0; --i)
  {
    a[i] ^= a[i+1];

    int j = i + p - 1;
    if (j <= n)
    {
      P[i] = a[i] ^ a[j+1];
    }
    else
    {
      P[i] = 0;
    }
  }

  int last_nonzero = n - p + 1;
  // build(0, 1, n);

  while (m--)
  {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1)
    {
      // from = max(1, a-p+1);
      // to = min(a, last_nonzero);
      // update_with = b;
      // update(1, 1, n);
      int from = max(1, a-p+1);
      int to = min(a, last_nonzero);
      int update_with = b;
      while (from <= to) P[from++] ^= update_with;
    }
    else
    {
      // from = a; to = b;
      // cout << query(0, 1, n) << "\n";
      int from = a;
      int to = b;
      int64_t res = 0;
      while (from <= to) res += P[from++];
      cout << res << "\n";
    }

  }

  return 0;
}
