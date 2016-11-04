#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 11;

char inc_cached[MAXN][MAXN];
char dec_cached[MAXN][MAXN];

int inc_cache[MAXN][MAXN];
int dec_cache[MAXN][MAXN];

int seq[MAXN], n;
vector<pair<int,int>> input;

int inc(int val, int pos) {
  if (pos == n) return 0;
  int &r = inc_cache[val][pos];
  if (inc_cached[val][pos]) return r;
  inc_cached[val][pos] = 1;
  r = inc(val, pos+1);
  if (seq[pos] >= val) {
    r = max(r, 1 + inc(seq[pos], pos+1));
  }
  return r;
}


int dec(int val, int pos) {
  if (pos == n) return 0;
  int &r = dec_cache[val][pos];
  if (dec_cached[val][pos]) return r;
  dec_cached[val][pos] = 1;
  r = dec(val, pos+1);
  if (seq[pos] <= val) {
    r = max(r, 1 + dec(seq[pos], pos+1));
  }
  return r;
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> n;

  input.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> input[i].first;
    input[i].second = i+1;
  }

  sort(input.begin(), input.end());

  for (int i = 0; i < n; ++i) {
    input[i].first = i+1;
    swap(input[i].first, input[i].second);
  }

  sort(input.begin(), input.end());

  for (int i = 0; i < n; ++i) {
    seq[i] = input[i].second;
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, inc(i, 0) + dec(i-1, 0));
    res = max(res, inc(i+1, 0) + dec(i, 0));
  }

  cout << res << "\n";

  return 0;
}
