#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int g;
  cin >> g;
  while (g--) {
    int n;
    cin >> n;

    stack<int> q;
    int removed = 0;
    for (int i = 0; i < n; ++i) {
      int cur; cin >> cur;
      if (!cur && !q.empty()) {
        int candidate = q.top(); q.pop();
        while (!q.empty() && q.top() == 0) {
          removed++;
          candidate = q.top(); q.pop();
        }
        q.push(candidate);
      }
      q.push(cur);
    }

    if (removed & 1) cout << "Alice\n";
    else cout << "Bob\n";
  }

  return 0;
}
