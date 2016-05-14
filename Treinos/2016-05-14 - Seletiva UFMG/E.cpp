#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  map<char, int> cnt;
  string s;

  while (getline(cin, s)) {
    for (char &c : s) if (isalpha(c)) {
      cnt[toupper(c)]++;
    }
  }

  vector<pair<int, char>> r;
  for (char c = 'A'; c <= 'Z'; ++c) r.push_back(make_pair(cnt[c], c));
  sort(r.begin(), r.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  for (auto &v : r) cout << v.second << " " << v.first << "\n";

  return 0;
}
