from math import ceil, floor, fabs, pi

DENOMS = [1, 7, 106, 113, 33102, 33215, 66317, 99532, 265381, 364913, 1360120, 1725033, 25510582, 52746197, 78256779, 131002976, 340262731, 811528438, 1963319607, 4738167652, 6701487259, 567663097408, 1142027682075, 1709690779483, 2851718461558, 44485467702853]
DENOMS.reverse()


def doit(d):
    n1 = ceil(pi * d)
    n2 = floor(pi * d)
    d1 = fabs(n1 / d - pi)
    d2 = fabs(n2 / d - pi)
    if d2 < d1:
        return d2, n2, d
    return d1, n1, d


mn, mx = map(int, input().split())

res, a, b = doit(mn)
found = False
for d in DENOMS:
    if mn <= d and d <= mx:
        res, a, b = doit(d)
        found = True
        break

if not found:
    for d in range(mn + 1, mx + 1):
        r, aa, bb = doit(d)
        if r < res:
            res, a, b = r, aa, bb

print('{}/{}'.format(a, b))
