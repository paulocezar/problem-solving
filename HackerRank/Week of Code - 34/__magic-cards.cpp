#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> cards;
map<pair<int,int>, int64_t> cache;

int64_t all;
int m;

int64_t doit(int from, int to) {
  if (cache.count({from, to})) return cache[{from, to}];

  unordered_set<int> seen;
  int rem = to-from+1;
  int64_t res = 0;
  for (int i = from-1; i < to; ++i) {

    vector<int> keep, turn;
    int64_t kk = 0, tt = 0;

    for (int x = 1; x <= m; ++x) {
      if (seen.count(x)) continue;
      if (binary_search(cards[i].begin(), cards[i].end(), x)) {
        keep.push_back(x);
        kk += 1LL * x * x;
      } else {
        turn.push_back(x);
        tt += 1LL * x * x;
      }
    }

    if (kk > tt) {
      res += kk;
      for (int v : keep) seen.insert(v);
    } else {
      res += tt;
      for (int v : turn) seen.insert(v);
    }

    rem--;

    if ((rem + seen.size()) >= m) {
      seen = {};
      res = all;
      break;
    }
  }

  return cache[{from, to}] = res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> m >> q;

  all = 0;
  for (int i = 1; i <= m; ++i) {
    all += 1LL * i * i;
  }

  cards.resize(n);

  for (auto& card : cards) {
    int xi; cin >> xi;
    card.resize(xi);
    for (int&v : card) cin >> v;
    sort(card.begin(), card.end());
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    int len = r-l+1;
    if (len >= m) {
      cout << all << "\n";
    } else {
      cout << doit(l, r) << "\n";
    }
  }

  return 0;
}
