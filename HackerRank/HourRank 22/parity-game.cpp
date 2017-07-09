#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int& v : a) { cin >> v; sum += v; }

  if (sum & 1) {
    if (n > 1) cout << "1\n";
    else cout << "-1\n";
  } else cout << "0\n";

  return 0;
}
