#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct portifolio_t {
  string portifolio_identifier;
  int64 portifolio_order;
  bool operator < (const portifolio_t &p) const {
    if (portifolio_order != p.portifolio_order) {
      return portifolio_order < p.portifolio_order;
    }
    return portifolio_identifier < p.portifolio_identifier;
  }
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  int64 minimum_trade_size, increment, available_units;
  cin >> minimum_trade_size >> increment >> available_units;

  auto tradeable = [&](int64 amount) {
    if (amount == 0) return true;
    int64 N = (amount - minimum_trade_size) / increment;
    return (N >= 0) && (amount == (minimum_trade_size + N*increment));
  };

  vector<portifolio_t> portifolios(T);
  int64 total_order = 0LL;
  for (auto &p : portifolios) {
    cin >> p.portifolio_identifier >> p.portifolio_order;
    total_order += p.portifolio_order;
  }
  sort(portifolios.begin(), portifolios.end());

  vector< pair<string, int64> > ans(T);

  for (int i = 0; i < T; ++i) {
    portifolio_t &p = portifolios[i];

    double proportional_allocation = double(double(p.portifolio_order) / double(total_order)) * available_units;

    int64 allocate = 0LL;

    if (proportional_allocation >= minimum_trade_size) {
      if (proportional_allocation >= p.portifolio_order) {
        allocate = p.portifolio_order;
      } else {
         int64 N = (proportional_allocation - minimum_trade_size) / increment;
         while (N >= 0) {
          int64 trie_to_allocate = minimum_trade_size + increment * N;
          if (tradeable(p.portifolio_order - trie_to_allocate)) {
            allocate = trie_to_allocate;
            break;
          }
          N--;
        }
      }
    } else {
      if ((proportional_allocation*2) > minimum_trade_size) {
        allocate = minimum_trade_size;
        if (!tradeable(p.portifolio_order - allocate)) allocate = 0LL;
      }
    }

    total_order -= p.portifolio_order;
    available_units -= allocate;

    ans[i].first = p.portifolio_identifier;
    ans[i].second = allocate;
  }

  sort(ans.begin(), ans.end());
  for (auto &r : ans) {
    cout << r.first << " " << r.second << "\n";
  }

  return 0;
}
