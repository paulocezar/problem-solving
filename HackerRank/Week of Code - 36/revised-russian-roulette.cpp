#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> locked(n);

  for (int& v : locked) cin >> v;

  int max_unlocks = accumulate(locked.begin(), locked.end(), 0);

  int min_unlocks = 0;
  for (auto i = 0; i+1 < locked.size(); ++i) {
    min_unlocks += locked[i];
    locked[i+1] = locked[i] ? 0 : locked[i+1];
  }
  min_unlocks += locked.back();

  cout << min_unlocks << " " << max_unlocks << "\n";

  return 0;
}
