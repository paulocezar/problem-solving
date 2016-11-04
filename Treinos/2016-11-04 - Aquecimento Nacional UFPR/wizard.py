#!/usr/bin/env python3

from math import log2

N, K = map(int, input().split())

if log2(N) <= K: print("Your wish is granted!")
else: print("You will become a flying monkey!")
