#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1024];
char stat[1024];

bool find_cycle(int u) {
  stat[u] = 1;
  for (int &v : gr[u]) {
    if (stat[v] == 1) return true;
    if (stat[v] == 2) continue;
    if (find_cycle(v)) return true;
  }
  stat[u] = 2;
  return false;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {

    for (int i = 0; i < 1024; ++i) gr[i].clear();
    map<string, int> attractions;

    int n;
    cin >> n; cin.ignore();
    while (n--) {
      string line;
      getline(cin, line);
      istringstream in(line);
      string attr;
      int prev = -1;
      while (getline(in, attr, ',')) {
        if (!attractions.count(attr)) attractions[attr] = attractions.size();
        if (prev != -1) gr[prev].push_back(attractions[attr]);
        prev = attractions[attr];
      }
    }

    n = attractions.size();
    bool ok = true;
    memset(stat, 0, sizeof(stat));

    for (int i = 0; i < n; ++i) {
      if (stat[i]) continue;
      if (find_cycle(i)) {
        ok = false;
        break;
      }
    }

    if (ok) cout << "ORDER EXISTS\n";
    else cout << "ORDER VIOLATION\n";
  }

  return 0;
}
