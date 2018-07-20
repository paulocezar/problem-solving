#include <bits/stdc++.h>

using namespace std;

bool starts_with(const string& s, const string& prefix) {
  return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
  return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const string prefix = "hydro";
  const string suffix = "ic";

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;

    if (starts_with(s, prefix) && ends_with(s, suffix)) cout << "non-metal acid\n";
    else if (ends_with(s, suffix)) cout << "polyatomic acid\n";
    else cout << "not an acid\n";
  }

  return 0;
}
