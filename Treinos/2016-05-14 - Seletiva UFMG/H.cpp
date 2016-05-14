#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string s1, s2;

bool cached[128][128][128];
bool cache[128][128][128];

bool ok(int i, int j, int k) {
  if (j > k) return (i == s1.size());
  if (i == s1.size()) return false;

  bool &ret = cache[i][j][k];
  if (cached[i][j][k]) return ret;
  cached[i][j][k] = true;
  ret = false;

  if (s1[i] == s2[j]) ret |= ok(i+1, j+1, k);
  if (s1[i] == s2[k]) ret |= ok(i+1, j, k-1);

  return ret;

}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> s1 >> s2;

  reverse(s1.begin(), s1.end());

  if (ok(0, 0, s2.size()-1)) cout << "S\n";
  else cout << "N\n";

  return 0;
}
