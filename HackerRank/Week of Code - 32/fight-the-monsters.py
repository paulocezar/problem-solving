#!/usr/bin/env python3

(n, hit, t) = map(int, input().split())
h = sorted(map(lambda x: (int(x) + hit - 1) // hit, input().split()))

res = 0
for hi in h:
    if t < hi:
        break
    t -= hi
    res += 1

print(res)
