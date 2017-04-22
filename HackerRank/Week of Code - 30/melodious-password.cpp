#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

static const int MAXN = 6;
static const string ALPH = "abcdefghijklmnopqrstuvwxz";
static const string VOWELS = "aeiou";

array<char, MAXN> buf;
int n;

inline bool is_vowel(char c) {
  return VOWELS.find(c) != string::npos;
}

void doit(int at) {
  if (at == n) {
    for (int i = 0; i < n; ++i) cout << buf[i];
    cout << '\n';
    return;
  }

  for (char c : ALPH) {
    if (at && is_vowel(c) == is_vowel(buf[at-1])) continue;
    buf[at] = c;
    doit(at+1);
  }
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  cin >> n;
  doit(0);

  return 0;
}
