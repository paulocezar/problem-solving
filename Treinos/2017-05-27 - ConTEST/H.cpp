#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

double p;

double cache[32][8];
int last_cached[32][8], cached_now;

double doit(int N, int H) {
  if (N == 0) return 1.0;
  double &res = cache[N][H];
  int &lc = last_cached[N][H];
  if (lc == cached_now) return res;
  lc = cached_now;
  res = p * doit(N-1, H);
  if (H) res += (1.0 - p) * doit(N, H-1);
  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N, H;
    cin >> N >> H >> p;
    cached_now++;
    cout << "Caso " << tc << ": " << doit(N, H) << "\n";
  }

  return 0;
}
