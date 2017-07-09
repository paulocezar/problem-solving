#!/usr/bin/env python3

from itertools import repeat


def expand(string):
    for i in range(len(string)):
        string.append(1 - string[i])


def create():
    string = [0]
    while len(string) <= 1000:
        expand(string)
    return string


s = create()
q = int(input())

for _ in repeat(None, q):
    x = int(input())
    print(s[x])
