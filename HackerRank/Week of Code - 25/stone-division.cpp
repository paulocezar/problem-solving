#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 S[16];
int m;

map<int64, int64> cache;

int64 grundy(int64 n) {
  if (cache.count(n)) return cache[n];

  set<int64> s;
  for (int i = 0; i < m; ++i) {
    if (n % S[i]) continue;
    if (S[i] & 1) {
      s.insert(grundy(n / S[i]));
    } else {
      s.insert(0);
    }
  }

  int64 r = 0;
  while (s.count(r)) r++;

  cache[n] = r;
  return r;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int64 n;
  cin >> n;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> S[i];
  }

  if (grundy(n)) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }

  return 0;
}
