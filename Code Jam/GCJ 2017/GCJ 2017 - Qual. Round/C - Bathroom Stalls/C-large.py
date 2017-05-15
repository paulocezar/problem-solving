#!/usr/bin/env python3

from heapq import heappush, heappop

T = int(input())
for t in range(T):
    (N, K) = map(int, input().split())

    h = [-N]
    cnt = {N: 1}

    while True:
      cur = -heappop(h)

      mn = (cur - 1) // 2
      mx = cur - 1 - mn

      if cnt[cur] >= K:
        break

      K -= cnt[cur]

      if mn not in cnt:
        heappush(h, -mn)
        cnt[mn] = 0
      cnt[mn] += cnt[cur]

      if mx not in cnt:
        heappush(h, -mx)
        cnt[mx] = 0
      cnt[mx] += cnt[cur]

    print('Case #%i:' % (t+1), mx, mn)
