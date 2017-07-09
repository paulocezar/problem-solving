#!/usr/env/bin python3

n = int(input())
d = map(int, input().split())
m = 4
for s in d:
    m *= s
print(m // 1024)
