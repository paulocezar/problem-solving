import re

T = int(raw_input())
for t in range(T):
    stack = re.sub(r'(.)(\1+)', r'\1', raw_input())
    ans = len(stack)
    if (((ans % 2) == 0) == (stack[0] == '-')): ans -= 1
    print 'Case #%i:' % (t+1), ans
