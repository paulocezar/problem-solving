import sys

from decimal import *
getcontext().prec = 6

def main():
    C=[[0 for j in range (0,1001)] for i in range (0,1001)] 

    for i in range (0,1001):
        C[i][0] = C[i][i] = 1
        for j in range (1,i):
            C[i][j] = C[i-1][j] + C[i-1][j-1]

    t=int(raw_input())

    while t:
        t -= 1
        s, n, m, k = [int(x) for x in raw_input().split()]
        okay = 0
        for friends in range(k,m):
            notfriends = n-1-friends
            if 0 <= notfriends and notfriends <= (s-m) :
                okay += C[m-1][friends] * C[s-m][notfriends]
            
        print (Decimal(okay) / Decimal(C[s-1][n-1]))
        
main()