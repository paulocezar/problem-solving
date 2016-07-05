#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[19];
int64 fat[19];

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  fat[0] = 1LL;
  bool sorted = true;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i-1];
    fat[i] = int64(i) * fat[i-1];
    sorted = sorted && ((i == 1) || (a[i-1] >= a[i-2]));
  }

  if (sorted) {
    cout << "0.000000\n";
  } else {
    sort(a, a+N);

    int64 seq = fat[N];
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
      if (a[i] == a[i-1]) {
        cnt++;
      } else {
        seq /= fat[cnt];
        cnt = 1;
      }
    }
    seq /= fat[cnt];

    cout << seq << ".000000\n";
  }


  return 0;
}
