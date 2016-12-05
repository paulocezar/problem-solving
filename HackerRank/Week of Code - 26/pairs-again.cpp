#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 19;
vector<int> divisors[MAXN];
vector<int> bs[MAXN];
vector<int> aux;
int last_seen[MAXN], seen_now;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int v = 1; v <= n; ++v) {
    for (int i = 1; i*i <= v; ++i) {
      if (v % i) continue;
      aux.push_back(i);
      if (i*i != v) divisors[v].push_back(v / i);
    }
    for (int j = aux.size()-1; j >= 0; --j) {
      divisors[v].push_back(aux[j]);
    }
    aux.resize(0);
  }

  for (int ax = 1; ax < n; ++ax) {
    int by = n - ax;
    for (int &a : divisors[ax]) {
      if (divisors[by][0] > a) bs[a].push_back(by);
    }
  }

  int res = 0;
  for (int a = 1; a <= n; ++a) {
    seen_now++;
    for (int &by : bs[a]) {
      for (int &b : divisors[by]) {
        if (b <= a) break;
        if (last_seen[b] != seen_now) {
          res++;
          last_seen[b] = seen_now;
        }
      }
    }
  }
  cout << res << "\n";


  return 0;
}
