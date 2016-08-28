#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXV = 1<<16;

vector<int> gr[MAXV];
vector<int> xs, ys, zs;

int N;

// int w[MAXV], pi[MAXV], parent[MAXV];
// unordered_set<int> RN[MAXV];

// struct comp {
//   bool operator ()( const int& a, const int& b ) const {
//     if (w[a] != w[b]) return w[a] > w[b];
//     return a > b;
//   }
// };

// set< int, comp > q;
// bool chordal(){

//   for (int i = N; i > 0; --i) {
//     int z = *q.begin();
//     q.erase(z);
//     pi[z] = i;

//     for (int &v : gr[z]) if (pi[v] == 0) {
//       q.erase(v);
//       w[v]++;
//       q.insert(v);
//     }
//   }

//   for (int i = 1; i <= N; ++i) {
//     for (int &v : gr[i]) if (pi[v] > pi[i]) {
//       RN[i].insert(v);
//       if (pi[v] < pi[parent[i]]) parent[i] = v;
//     }
//   }

//   for (int i = 1; i <= N; ++i) {
//     if (parent[i] == 0) continue;
//     RN[i].erase(parent[i]);
//     for (const int &x : RN[i]) {
//       if (!RN[parent[i]].count(x)) return false;
//     }
//     RN[i].insert(parent[i]);
//   }

//   return true;
// }

void addEdges(map<int, vector<int>> occ) {
  for (auto &ntry : occ) {
    auto &ls = ntry.second;
    int n = ls.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        gr[ls[i]].push_back(ls[j]);
        gr[ls[j]].push_back(ls[i]);
      }
    }
  }
}

void print(int idx) {
  idx--;
  cout << xs[idx] << " " << ys[idx] << " " << zs[idx];
}

unordered_set<int> cur, best;

vector<int> order;

void doit(int idx) {
  if (idx == N) {
    if (cur.size() > best.size()) {
      best = cur;
    }
    return;
  }

  int estimate = cur.size() + N-idx;
  if (estimate <= int(best.size())) return;

  bool can_use = true;

  for (int &v : gr[order[idx]]) {
    if (cur.count(v)) {
      can_use = false;
      break;
    }
  }

  if (can_use) {
    cur.insert(order[idx]);
    doit(idx+1);
    cur.erase(order[idx]);
  }

  doit(idx+1);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  N = 0;

  map<int, vector<int>> appearsX;
  map<int, vector<int>> appearsY;
  map<int, vector<int>> appearsZ;

  for (int xi = 0; xi <= n; ++xi) {
    for (int yi = 0; yi <= n; ++yi) {
      int zi = n - xi - yi;
      if (zi >= 0) {
        N++;
        appearsX[xi].push_back(N);
        appearsY[yi].push_back(N);
        appearsZ[zi].push_back(N);
        xs.push_back(xi);
        ys.push_back(yi);
        zs.push_back(zi);
      }
    }
  }

  // for (int i = 1; i <= N; ++i) {
  //   gr[i].clear();
  //   w[i] = 0;
  //   pi[i] = 0;
  //   parent[i] = 0;
  //   q.insert(i);
  //   RN[i].clear();
  // }

  addEdges(appearsX);
  addEdges(appearsY);
  addEdges(appearsZ);

  order.resize(N);
  for (int i = 0; i < N; ++i) order[i] = i+1;
  random_shuffle(order.begin(), order.end());

  doit(0);
  cout << best.size() << endl;
  for (const int &el : best) {
    print(el); cout << "\n";
  }

  return 0;
}
