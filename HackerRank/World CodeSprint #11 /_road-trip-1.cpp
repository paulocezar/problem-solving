#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int LGMN = 18;
const int MAXN = 1 << LGMN;

int g[MAXN], w[MAXN];
int64_t p[MAXN];

struct node_t {
  int64_t cheapest, remaining_gas, cost;
  vector<int64_t> bought_amount;
  vector<int64_t> at_price;
  vector<int64_t> acm;

  void init() {
    cheapest = 2e9;
    remaining_gas = 0;
    cost = 0;
    bought_amount = {};
    at_price = {};
    acm = {};
  }

  void extend(const node_t& l, int mid, int hi) {
    cheapest = l.cheapest;
    remaining_gas = l.remaining_gas;
    cost = l.cost;
    bought_amount = l.bought_amount;
    at_price = l.at_price;
    acm = l.acm;

    for (int x = mid; x < hi; ++x) {
      remaining_gas += g[x];
      cheapest = min(cheapest, p[x]);

      remaining_gas -= w[x];
      if (remaining_gas < 0LL) {
        bought_amount.push_back((bought_amount.size() ? bought_amount.back() : 0) - remaining_gas);
        at_price.push_back(cheapest);
        int64_t cur_cost = -remaining_gas * cheapest;
        acm.push_back((acm.size() ? acm.back() : 0) + cur_cost);

        cost += cur_cost;
        remaining_gas = 0;
      }
    }
  }
};

node_t segt[1 << (LGMN + 1)];

void build(int node, int lo, int hi) {
  if (lo == hi) {
    segt[node].init();
  } else {
    int mid = (lo + hi) >> 1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);
    segt[node].extend(segt[ls], mid, hi);
  }
}

node_t res;
int from, to;

void get(int node, int lo, int hi) {
  if (hi < from || lo > to) return;
  if (from <= lo && hi <= to) {
    if (lo == from) {
      res.cheapest = segt[node].cheapest;
      res.remaining_gas = segt[node].remaining_gas;
      res.cost = segt[node].cost;
//cout << "COPY " << lo << " " << hi << endl;
//cout << "\tcheapest " << res.cheapest << endl;
//cout << "\tremaining_gas " << res.remaining_gas << endl;
//cout << "\tcost " << res.cost << endl;
    } else {
//cout << "EXTEND " << lo << " " << hi << endl;
      res.remaining_gas += g[lo-1];
      res.cheapest = min(res.cheapest, p[lo-1]);
      res.remaining_gas -= w[lo-1];
      res.cost += segt[node].cost;
//cout << "from " << lo-1 << " to " << lo << " " << res.remaining_gas << " remains.. (" << res.cheapest << ")" << endl;
      if (res.remaining_gas < 0LL) {

        res.cost -= res.remaining_gas * res.cheapest;
        res.remaining_gas = 0;
      }

      int cover = upper_bound(segt[node].bought_amount.begin(), segt[node].bought_amount.end(), res.remaining_gas) - segt[node].bought_amount.begin();
//cout << res.remaining_gas << " covers " << cover <<  " from new node .." << endl;
      if (cover != 0) {
//cout << " ~~ " << segt[node].bought_amount[cover-1] << endl;
//cout << " >> " << segt[node].acm[cover-1] << endl;
        res.cost -= segt[node].acm[cover-1];
        res.remaining_gas -= segt[node].bought_amount[cover-1];
      }
//cout << "new cost: " << res.cost << " .. " << res.remaining_gas << endl;
      int l = cover+1, r = segt[node].at_price.size() - 1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (segt[node].at_price[m] < res.cheapest) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      if ((cover+1) <= r) {
//cout << res.cheapest << " is new minimum from " << cover+1 << " to " << r << endl;
        res.cost -= segt[node].acm[r] - segt[node].acm[cover];
        res.cost += (segt[node].bought_amount[r] - segt[node].bought_amount[cover]) * res.cheapest;
      }

      if ((res.remaining_gas > 0LL) && (cover < int(segt[node].bought_amount.size()))) {
        int64_t amnt = segt[node].bought_amount[cover] - (cover ? segt[node].bought_amount[cover - 1] : 0);
        res.cost -= amnt * segt[node].at_price[cover];
        amnt -= res.remaining_gas;
        res.cost += amnt * min(res.cheapest, segt[node].at_price[cover]);
        res.remaining_gas = 0;
      }

      res.remaining_gas += segt[node].remaining_gas;

      res.cheapest = min(res.cheapest, segt[node].cheapest);
//cout << "\tcheapest " << res.cheapest << endl;
//cout << "\tremaining_gas " << res.remaining_gas << endl;
//cout << "\tcost " << res.cost << endl;
    }
    return;
  }
  int mid = (lo + hi) >> 1;
  int ls = (node << 1) + 1;
  int rs = ls + 1;
  get(ls, lo, mid);
  get(rs, mid+1, hi);
}

int64_t brute(int x, int y) {
  int64_t gas = 0LL, cheapest = 2e9, cost = 0LL;
    while (x != y) {
      gas += g[x];
      cheapest = min(cheapest, p[x]);

      gas -= w[x];

      if (gas < 0LL) {
        cost -= gas * cheapest;
        gas = 0;
      }

      x++;
    }
  return cost;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i < n; ++i) {
    cin >> w[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> g[i] >> p[i];
  }

  build(0, 1, n);

  while (q--) {
    cin >> from >> to;
    if (n < 10000) cout << brute(from, to) << "\n";
    else {
      get(0, 1, n);
      cout << res.cost << "\n";
    }
  }

  return 0;
}
