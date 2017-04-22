
BASES = (2, 3, 5, 7, 11, 13, 17)

DIGS = 17

tens = [1]
mn = [0]
mx = [0]

for i in range(1, DIGS):
    tens.append(10 * tens[i - 1])
    mn.append(10 * mn[i - 1] + 2)
    mx.append(10 * mx[i - 1] + 7)


def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, (2 ** i) * d, n) == n - 1:
            return False
    return True


def is_prime(n):
    if n in BASES:
        return True
    if any((n % p) == 0 for p in BASES):
        return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1

    return not any(_try_composite(a, d, n, s) for a in BASES)


L, R = map(int, input().split())


def build(ds, cur):
    if ds == 0:
        if is_prime(cur):
            return 1
        return 0

    res = 0
    if cur == 0:
        res += build(ds - 1, 0)

    if (cur + mn[ds]) > R:
        return res
    if (cur + mx[ds]) < L:
        return res

    for d in (2, 3, 5, 7):
        res += build(ds - 1, cur + tens[ds - 1] * d)

    return res


md, ax = 0, R
while ax:
    md += 1
    ax = ax // 10

print(build(md, 0))
