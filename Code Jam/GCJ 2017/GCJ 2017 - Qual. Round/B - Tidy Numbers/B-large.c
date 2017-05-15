#include <stdio.h>

int ds[32];

int main(int argc, char* argv[]) {

  int T;
  scanf("%d", &T);

  for (int tc = 1; tc <= T; ++tc) {
    long long n;
    scanf("%lld", &n);

    int len = 0;
    while (n) {
      ds[len++] = n % 10; n /= 10;
    }
    ds[len] = 0;

    int idx = len-2;
    while (idx >= 0) {
      if (ds[idx] < ds[idx+1]) break;
      idx--;
    }

    if (idx >= 0) {
      idx++;
      ds[idx]--;
      while (ds[idx] < ds[idx+1]) {
        idx++;
        ds[idx]--;
      }

      idx--;
      while (idx >= 0) ds[idx--] = 9;
    }

    for (int i = len-1; i >= 0; --i) {
      n = 10LL*n + ds[i];
    }

    printf("Case #%d: %lld\n", tc, n);
  }

  return 0;
}
