#!/usr/bin/env python3


def factors_of(x):
    res = []
    for i in range(2, x + 1):
        if (i * i) > x:
            break
        if (x % i) != 0:
            continue
        pw = 0
        while (x % i) == 0:
            x = x // i
            pw += 1

        res.append((i, pw))

    if x != 1:
        res.append((x, 1))

    return res


n = int(input())
s = input()


def count(jj, i, p, prime_factors):
    if i > n:
        return 0

    if p >= len(prime_factors):
        if s[i - 1] != 'a':
            return 0
        k = jj // i
        if (k > n) or (s[k - 1] != 'c'):
            return 0
        return 1

    r = 0
    for qnt in range(0, prime_factors[p][1] + 1):
        r += count(jj, i, p + 1, prime_factors)
        i *= prime_factors[p][0]

    return r


res = 0
for j in range(1, n + 1):
    if s[j - 1] == 'b':
        factors = list(map(lambda x: (x[0], 2 * x[1]), factors_of(j)))
        res += count(j * j, 1, 0, factors)

print(res)
