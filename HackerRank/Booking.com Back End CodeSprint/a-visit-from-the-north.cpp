#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int must_stay[32];
vector<pair<int,int>> gr[32];
string cname[32];

map<int, int> cache[21][6][17];
int doit(int seen, int at, int day, int rem) {
  if (day > 5) return 0;
  if (cache[at][day][rem].count(seen)) return cache[at][day][rem][seen];

  int best = 0;
  for (auto e : gr[at]) {
    int v = e.first, w = e.second;
    if (seen & (1<<v)) continue;
    int nd = day;
    int nr = rem;
    if (w > nr) nd++, nr = 16;
    nr -= w;
    if (nr == 0) nd++, nr = 16;
    int ms = must_stay[v];
    while ((ms > nr) && (nd < 5)) {
      ms -= nr;
      nd++;
      nr = 16;
    }
    if ((ms > nr) || (nd > 5)) {
      continue;
    }
    nr -= ms;
    if (nr == 0) nd++, nr = 16;
    best = max(best, 1 + doit(seen | (1<<v), v, nd, nr));
  }

  cache[at][day][rem][seen] = best;
  return best;
}

void build(int seen, int at, int day, int rem) {
  if (day > 5) return;
  int best = cache[at][day][rem][seen];
  if (best == 0) return;

  for (auto e : gr[at]) {
    int v = e.first, w = e.second;
    if (seen & (1<<v)) continue;
    int nd = day;
    int nr = rem;
    if (w > nr) nd++, nr = 16;
    nr -= w;
    if (nr == 0) nd++, nr = 16;
    int ms = must_stay[v];
    while ((ms > nr) && (nd < 5)) {
      ms -= nr;
      nd++;
      nr = 16;
    }
    if ((ms > nr) || (nd > 5)) {
      continue;
    }
    nr -= ms;
    if (nr == 0) nd++, nr = 16;
    if (best == (1 + doit(seen | (1<<v), v, nd, nr))) {
      cout << cname[v] << "\n";
      build(seen | (1<<v), v, nd, nr);
      return;
    }
  }
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n; cin.ignore();
  n++;

  map<string, int> name_to_i;
  name_to_i["Bevagna"] = 0;

  for (int i = 1; i < n; ++i) {
    string line; getline(cin, line);
    cname[i] = "";
    int j = 0;
    while (line[j] != ',') cname[i] += line[j++]; j++;
    name_to_i[cname[i]] = i;
    must_stay[i] = 0;
    while (j < int(line.size())) {
      must_stay[i] = 10*must_stay[i] + int(line[j++]-'0');
    }
  }

  int e;
  cin >> e; cin.ignore();
  for (int i = 0; i < e; ++i) {
    string line; getline(cin, line);
    string sc1 = "", sc2 = ""; int h = 0;
    int j = 0;
    while (line[j] != ',') sc1 += line[j++]; j++;
    while (line[j] != ',') sc2 += line[j++]; j++;
    while (j < int(line.size())) {
      h = 10*h + int(line[j++]-'0');
    }
    if (h > 16) continue;
    int c1 = name_to_i[sc1], c2 = name_to_i[sc2];
    gr[c1].push_back({c2, h});
    gr[c2].push_back({c1, h});
  }

  int ans = doit(1, 0, 0, 16);
  if (ans) build(1, 0, 0, 16);
  else cout << "NONE\n";

  return 0;
}
