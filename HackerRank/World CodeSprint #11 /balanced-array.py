#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

s1, s2 = 0, 0
for i in range(n // 2):
    s1 += a[i]
    s2 += a[n - i - 1]

print(abs(s1 - s2))
