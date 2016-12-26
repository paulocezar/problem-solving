#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;
const int NUM_VTX = 394;
const int MAXN = 1 << 19;

auto primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

map<int,int> vertex;
vector<int> gr[NUM_VTX];

int ans[MAXN];

int digsum(int digs, int val) {
  int sum = 0;
  while (digs--) {
    sum += val % 10;
    val /= 10;
  }
  return sum;
}

bool is_prime(int val) {
  return binary_search(primes.begin(), primes.end(), val);
}

set<int> small;
void gen_vertices(int cur = 0, int len = 0) {
  if (len && len < 5) small.insert(cur);
  if (len == 5) {
    if (is_prime(digsum(5, cur))) {
      int idx = vertex.size() + 1;
      vertex[cur] = idx;
    }
    return;
  }
  for (int put = 0; put < 10; ++put) {
    bool ok = true;
    int nxt = 10*cur + put;
    if (len >= 2 && !is_prime(digsum(3, nxt))) {
      ok = false;
    }
    if (len >= 3 && !is_prime(digsum(4, nxt))) ok = false;
    if (ok) gen_vertices(nxt, len+1);
  }
}

void gen_edges() {
  int cnt = 0;
  for (auto &vtx : vertex) {
    if (vtx.first >= 10000) {
      gr[0].push_back(vtx.second);
      cnt++;
    }
    for (int put = 0; put < 10; ++put) {
      int v = (vtx.first % 10000) * 10 + put;
      if (vertex.count(v)) gr[vtx.second].push_back(vertex[v]);
    }
  }
}

void build_graph() {
  gen_vertices();
  gen_edges();
}

int dp[2][NUM_VTX];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  build_graph();

  auto len = [](int x) {
    int d = 0;
    while (x) { d++; x/=10; }
    return d;
  };
  for (int v : small) {
    ans[len(v)]++;
  }

  for (int i = 0; i < NUM_VTX; ++i) dp[0][i] = 1;

  int old = 0, cur = 1;
  for (int need = 1; (need+4) < MAXN; ++need) {

    for (int at = 0; at < NUM_VTX; ++at) {
      dp[cur][at] = 0;
      for (int v : gr[at]) {
        dp[cur][at] += dp[old][v];
        if (dp[cur][at] >= MOD) dp[cur][at] -= MOD;
      }
    }

    ans[need+4] = dp[cur][0];

    old = 1 - old;
    cur = 1 - cur;
  }

  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    cout << ans[n] << "\n";
  }

  return 0;
}
