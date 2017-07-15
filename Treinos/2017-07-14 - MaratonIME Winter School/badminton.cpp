#include <bits/stdc++.h>

using namespace std;

double p[2];
double cache[2][31][31];
char cached[2][31][31];

double solve(int w, int b, int t) {
  if ((b >= 21 || t >= 21) && (abs(b-t) >= 2 || max(b, t) == 30)) {
    if (b > t) return 1.0;
    return 0.0;
  }

  if (cached[w][b][t]) return cache[w][b][t];
  cached[w][b][t] = 1;

  return cache[w][b][t] = (p[w] * solve(0, b+1, t) + (1.0 - p[w]) * solve(1, b, t+1));
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int s, r;
  cin >> s >> r;

  p[0] = s / 1e9;
  p[1] = r / 1e9;

  double rs = solve(0, 0, 0);
  double rr = solve(1, 0, 0);

  cout << fixed << setprecision(13) << rs * rs + 2.0 * rs * (1.0-rs) * rr << "\n";

  return 0;
}
