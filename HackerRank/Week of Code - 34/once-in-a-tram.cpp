#include <bits/stdc++.h>

using namespace std;

bool is_lucky(int x) {
  int s = 0;
  while (x) {
    if (x > 999) s += x % 10;
    else s -= x % 10;
    x /= 10;
  }
  return (s == 0);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  n++;
  while (!is_lucky(n)) n++;
  cout << n << "\n";

  return 0;
}
