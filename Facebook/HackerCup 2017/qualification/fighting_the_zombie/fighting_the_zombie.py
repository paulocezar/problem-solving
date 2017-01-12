def parse(s):
    v = (0, 0, 0)

    i = 0, sgn = -1
    for c in s:
        if '0' <= c and c <= '9':
            v[i] = 10 * v[i] + int(c - '0')
        else:
            i += 1
            if c == '-':
                sgn = -1
    v[2] *= sgn
    return v


cache = {}


def solve(sides, rem, need):
    if rem >= need:
        return 1.0
    if rem * sides < need:
        return 0.0

    if (sides, rem, need) in cache:
        return cache[(rem, need)]

    res = 0.0
    for i in range(1, sides + 1):
        res += solve(sides, rem - 1, max(0, need - i))
    res /= sides
    cache[(sides, rem, need)] = res
    return res


T = int(input())
for tc in range(1, T + 1):
    H, S = map(int, input().split())

    spell = map(parse, input().split())
    res = 0.0
    for i in range(0, S):
        cur = solve(spell[i][1], spell[i][0], max(0, H + spell[i][2]))
        res = max(res, cur)

    print('Case #{}: {}'.format(tc, res))

