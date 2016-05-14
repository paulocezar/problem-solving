#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  vector<int> cnt(26, 0);
  auto put = [](int what){ cout << char('a'+what); };

  int bst = -1, nz = 0, frst = -1;
  for (int i = 0; i < 26; ++i) {
    cin >> cnt[i];
    if (cnt[i]) {
      nz++;
      if (frst == -1) frst = i, bst = i;
      if (cnt[i] < cnt[bst]) bst = i;
    }
  }

  put(bst);
  cnt[bst]--;

  if (!cnt[bst] || (bst != frst)) goto hell;

  if (cnt[bst] == 1) {
    put(bst);
    cnt[bst]--;
  } else if (nz >= 2) {
    int ot = -1;
    for (int i = 0; i < 26; ++i) {
      if (i == bst) continue;
      if (cnt[i]) { ot = i; break; }
    }
    put(bst); cnt[bst]--;
    while (cnt[ot] && cnt[bst]) {
      put(ot);
      put(bst);
      cnt[ot]--;
      cnt[bst]--;
    }
  }

hell:
  for (int i = 0; i < 26; ++i) {
    while (cnt[i]) { put(i); cnt[i]--; }
  }

  cout << "\n";

  return 0;
}
