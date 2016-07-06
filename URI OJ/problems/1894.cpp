#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string label[1<<14];
vector<int> gr[1<<15];

int N, idx;

pair<int,int> doit(int u) {
  if (u <= N) {
    return {0, 1<<(label[u][idx]-'a')};
  }

  auto l = doit(gr[u][0]);
  auto r = doit(gr[u][1]);
  int c = l.first + r.first, cand = l.second & r.second;

  if (!cand) {
    cand = l.second | r.second;
    c++;
  }

  return {c, cand};
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int L;
  cin >> N >> L;

  for (int i = 1; i <= N; ++i) cin >> label[i];

  int M = 2 * (N-1);

  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    if (u < v) swap(u, v);
    gr[u].push_back(v);
  }

  int cost = 0;
  string lex = "";
  for (idx = 0; idx < L; ++idx) {
    auto r = doit(2*N - 1);
    cost += r.first;
    for (int i = 0; i < 26; ++i) if (r.second & (1<<i)) {
      lex += char('a'+i);
      break;
    }
  }

  cout << cost << "\n" << lex << "\n";

  return 0;
}
