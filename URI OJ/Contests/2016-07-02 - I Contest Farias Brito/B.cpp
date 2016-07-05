#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1000;

int N, M;
vector< int > gr[MAXN];
bool seen[MAXN];
int m[MAXN], m1[MAXN];

int dfs(int u) {
  if (u < 0) return 1;
  if (seen[u]) return 0;
  seen[u] = true;
  for (int &v : gr[u]) {
    if (dfs(m1[v])) {
      m[u] = v;
      m1[v] = u;
      return 1;
    }
  }
  return 0;
}

int dfsExp(int u) {
  for (int i = 0; i < N; ++i) seen[i] = false;
  return dfs(u);
}


int bipMatch() {
  for (int i = 0; i < N; ++i) m[i] = -1;
  for (int i = 0; i < M; ++i) m1[i] = -1;
  int aug, ans = 0;
  do {
    aug = 0;
    bool first = true;
    for (int i = 0; i < N; ++i) if (m[i] < 0) {
      if (first) aug += dfsExp(i);
      else aug += dfs(i);
      first = false;
    }
    ans += aug;
  } while (aug);
  return ans;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  string line;
  while (getline(cin, line)) if (line != "") break;

  istringstream in(line);
  in >> N >> M;

  map<char, int> cnt[N];
  for (int i = 0; i < N; ++i) {
    string cmt;
    while (getline(cin, cmt)) if (cmt != "") break;
    for (char &c : cmt) cnt[i][toupper(c)]++;
  }

  for (int i = 0; i < M; ++i) {
    while (getline(cin, line)) if (line != "") break;

    int jj = 0;
    while (!isalpha(line[jj])) jj++;
    char fav = toupper(line[jj]);
    line = line.substr(jj+1);
    istringstream in2(line);
    int nfav;
    in2 >> nfav;
    for (int j = 0; j < N; ++j) {
      if (cnt[j][fav] >= nfav) gr[j].push_back(i);
    }
  }

  cout << bipMatch() << "\n";

  return 0;
}
