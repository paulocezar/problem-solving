// USE BRUTE FORCE FOR SMALL TESTS
#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1 << 17;

int a[MAXN];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int64 res = 0LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      res = max(res, int64(a[i] & a[j]) * int64(a[i] | a[j]));
    }
  }
  cout << res << "\n";

  return 0;
}

// FOLLOWING WRONG SOLUTION MIGHT GET FULL SCORE THOUGH
// #include <bits/stdc++.h>

// typedef long long int64;
// typedef unsigned long long uint64;

// using namespace std;

// const int MAXN = 1 << 17;

// int a[MAXN];

// int main(int argc, char* argv[]) {

//   ios::sync_with_stdio(false);

//   int n;
//   cin >> n;

//   for (int i = 0; i < n; ++i) {
//     cin >> a[i];
//   }
//   sort(a, a+n);

//   int64 res = 0LL;
//   for (int i = 0; i+1 < n; ++i) {
//     res = max(res, int64(a[i] & a[i+1]) * int64(a[i] | a[i+1]));
//   }
//   cout << res << "\n";

//   return 0;
// }
