#include <bits/stdc++.h>

#include "message.h"
#include "rps.h"

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

char op(char a) {
  switch(a) {
    case 'R': return 'S';
    case 'P': return 'R';
    case 'S': return 'P';
  }
  return a;
}

bool wins(char a, char b) {
  if (a == b) return true;
  return b == op(a);
}

int simulate(string &favorite) {
  int len = favorite.size();
  vector<int> ids(len);

  for (int i = 0; i < len; ++i) ids[i] = i;

  while (len > 1) {
    for (int i = 0; i < len; i+=2) {
      if (wins(favorite[ids[i]], favorite[ids[i+1]])) ids[i>>1] = ids[i];
      else ids[i>>1] = ids[i+1];
    }
    len /= 2;
  }

  return ids[0];
}

int main() {

  int _nodes = NumberOfNodes();
  int _id = MyNodeId();

  if (_nodes == 100) { _nodes = 64; }
  else { _nodes = 8; }

  int N = GetN();
  int NN = 1<<N;

  while ((NN / _nodes) < 2) _nodes /= 2;

  if (_id > _nodes) return 0;

  if (_id) {
    int len = NN / _nodes;
    int lo = (_id-1) * len, hi = _id * len;
    string favs = "";
    for (int i = lo; i < hi; ++i) {
      char c = GetFavoriteMove(i);
      favs += c;
    }
    int r = lo + simulate(favs);
    PutInt(0, r);
    Send(0);
  } else {
    vector<int> ids;
    string favs = "";
    for (int node = 1; node <= _nodes; ++node) {
      Receive(node);
      int id = GetInt(node);
      ids.push_back(id);
      favs += GetFavoriteMove(id);
    }
    cout << ids[simulate(favs)] << endl;
  }

  return 0;
}
