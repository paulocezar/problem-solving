#include <bits/stdc++.h>

using namespace std;

const int MAXN = 128;

int G[MAXN], P;

unordered_map<int, int> cache[4];
int cnt[4];

inline int getkey() {
  int k = 0;
  for (int i = 0; i < P; ++i) k = (k << 7) | cnt[i];
  return k;
}

int solve(int groups, int rem) {
  if (!groups) return 0;

  int k = getkey();
  if (cache[rem].count(k)) return cache[rem][k];
  int &res = cache[rem][k];
  res = 2e9;

  if (rem) {
    if (cnt[0]) {
      cnt[0]--;
      res = min(res, solve(groups-1, rem - 1));
      cnt[0]++;
    }
    for (int r = 1; r < P; ++r) {
      if (cnt[r]) {
        cnt[r]--;
        int cur = ((P + r - rem)%P);
        if (!cur) cur = P;
        res = min(res, solve(groups-1, P - cur));
        cnt[r]++;
      }
    }
    res++;
  } else {
    for (int r = 1; r < P; ++r) {
      if (cnt[r]) {
        cnt[r]--;
        res = min(res, solve(groups-1, P - r));
        cnt[r]++;
      }
    }
    if (cnt[0]) {
      cnt[0]--;
      res = min(res, solve(groups-1, P - 1));
      cnt[0]++;
    }
  }

  return res;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N >> P;

    memset(cnt, 0, sizeof(cnt));
    int nonzero = 0;

    for (int i = 0; i < N; ++i) {
      cin >> G[i];
      if (G[i] == 1) {
        nonzero++, cnt[0]++;
      } else {
        G[i] %= P;
        if (G[i])
          nonzero++, cnt[G[i]]++;
      }
    }

    for (int i = 0; i < P; ++i) cache[i].clear();

    cout << "Case #" << tc << ": " << N - solve(nonzero, 0) << "\n";
  }

  return 0;
}
