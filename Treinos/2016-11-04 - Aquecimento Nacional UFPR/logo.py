#!/usr/bin/env python3

from math import sqrt, cos, sin, pi

def rotate(x, y, deg):
    deg = deg * pi / 180.0
    return (x*cos(deg) - y*sin(deg), x*sin(deg) + y*cos(deg))

def move(x, y, dx, dy, units):
    return (x + units*dx, y + units*dy)

t = int(input())

while t:
    t -= 1
    cm = int(input())
    x, y = 0, 0
    dx, dy = 1, 0
    while cm:
        cm -= 1
        wt, am = input().split()
        if wt == "fd":
            x, y = move(x, y, dx, dy, int(am)) 
        elif wt == "bk":
            x, y = move(x, y, dx, dy, -int(am))
        elif wt == "rt":
            dx, dy = rotate(dx, dy, int(am))
        else: 
            dx, dy = rotate(dx, dy, -int(am))
    print(round(sqrt(x*x + y*y)))
