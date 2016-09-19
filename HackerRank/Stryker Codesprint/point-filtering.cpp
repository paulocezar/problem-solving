#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

struct point_t {
  double x, y, z;
};

point_t pt[MAXN];
int idx[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, b, k;
  cin >> n >> b;

  for (int i = 0; i < n; ++i) {
    cin >> k;
    cin >> pt[k].x >> pt[k].y >> pt[k].z;
    idx[i] = k;
  }

  sort(idx, idx+n, [](const int & a, const int & b) -> bool {
    return pt[a].z > pt[b].z;
  });

  set<int> current;
  for (int i = 0; i < b; ++i) current.insert(idx[i]);

  string cmd;
  cout << fixed << setprecision(3);
  while (cin >> cmd >> k) {
    if (!current.count(k)) {
      cout << "Point doesn't exist in the bucket.\n";
      continue;
    }
    if (tolower(cmd[0]) == 'f') {
      cout << k << " = (" << pt[k].x << "," << pt[k].y << "," << pt[k].z << ")\n";
    } else {
      if ((b+1) <= n) {
        cout << "Point id " << k << " removed.\n";
        current.erase(k);
        current.insert(idx[b++]);
      } else {
        cout << "No more points can be deleted.\n";
      }
    }
  }

  return 0;
}
