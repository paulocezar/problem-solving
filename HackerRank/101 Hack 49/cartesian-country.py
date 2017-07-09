#!/usr/env/bin python3

(x1, y1) = map(int, input().split())
(x2, y2) = map(int, input().split())
(xC, yC) = map(int, input().split())

h = 2 * min(x2 - xC, xC - x1) + 1
w = 2 * min(y2 - yC, yC - y1) + 1

print((h * w - 1) // 2)
