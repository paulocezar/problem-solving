#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 subtract(int64 a, int64 b, int64 mod) {
    int64 res = a-b;
    if (res < 0LL) res = (mod - ((-res)%mod));
    return (res % mod);
}

int64 fpw(int64 a, int64 b, int64 mod) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

#define MAXN 100100

int64 P[2];

int64 seq[MAXN];

int64 iRi[2][MAXN], Ri[2][MAXN], invRi[2][MAXN];
int64 A[2][1<<19], B[2][1<<19], sum[2][1<<19];
    
int X, Y, g;
int64 incA[2], incB[2];

void build(int node, int lo, int hi) {
    for (int p = 0; p < 2; ++p) A[p][node] = B[p][node] = 0LL;
    
    if (lo == hi) {
        for (int p = 0; p < 2; ++p) sum[p][node] = seq[lo] % P[p];
    } else {
        int mid = (lo + hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        for (int p = 0; p < 2; ++p) sum[p][node] = (sum[p][ls]+sum[p][rs]) % P[p];
    }

}

void propagate(int node, int lo, int hi) {
    if (lo != hi) {
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        for (int p = 0; p < 2; ++p) {
            A[p][ls] += A[p][node]; A[p][ls] %= P[p];
            B[p][ls] += B[p][node]; B[p][ls] %= P[p];
            A[p][rs] += A[p][node]; A[p][rs] %= P[p];
            B[p][rs] += B[p][node]; B[p][rs] %= P[p];
        }
    }
    
    for (int p = 0; p < 2; ++p) {
        sum[p][node] += (((A[p][node] * subtract(iRi[p][hi],iRi[p][lo-1],P[p]))%P[p]) + ((B[p][node] * subtract(Ri[p][hi],Ri[p][lo-1],P[p]))%P[p]))%P[p];
        sum[p][node] %= P[p];
        A[p][node] = B[p][node] = 0LL;    
    }
}



void update(int node, int lo, int hi) {
    if (A[0][node] || A[1][node] || B[0][node] || B[1][node]) propagate(node, lo, hi);
    if ((X > hi) || (Y < lo)) return;
    
    if ((X <= lo) && (hi <= Y)) {
        for (int p = 0; p < 2; ++p) {
            A[p][node] += incA[p]; A[p][node] %= P[p];
            B[p][node] += incB[p]; B[p][node] %= P[p];
        }
        if (A[0][node] || A[1][node] || B[0][node] || B[1][node]) propagate(node, lo, hi);
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        update(ls,lo,mid);
        update(rs,mid+1,hi);
        for (int p = 0; p < 2; ++p) sum[p][node] = (sum[p][ls]+sum[p][rs]) % P[p];
    }
    
}

void update2(int node, int lo, int hi) {
    if (A[0][node] || A[1][node] || B[0][node] || B[1][node]) propagate(node, lo, hi);
    if ((X > hi) || (X < lo)) return;
    
    if (lo == hi) {
        sum[1][node] = fpw(sum[1][node],g,P[1]);
        sum[0][node] = sum[1][node] % P[0];
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        update2(ls,lo,mid);
        update2(rs,mid+1,hi);
        for (int p = 0; p < 2; ++p) sum[p][node] = (sum[p][ls]+sum[p][rs]) % P[p];
    }
}

int64 get(int node, int lo, int hi) {
    if (A[0][node] || A[1][node] || B[0][node] || B[1][node]) propagate(node, lo, hi);
    if ((X > hi) || (Y < lo)) return 0LL;
    
    if ((X <= lo) && (hi <= Y)) return sum[0][node];
    
    int mid = (lo+hi)>>1;
    int ls = (node<<1) + 1;
    int rs = (node<<1) + 2;
    int64 ret = 0LL;
    ret += get(ls,lo,mid);
    ret += get(rs,mid+1,hi);
    return ret % P[0];
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N, Q, cmd;
    int64 R, S, D;
    
    iRi[0][0] = iRi[1][0] = Ri[0][0] = Ri[1][0] = 0LL;
    
    cin >> T;
    while (T--) {
        cin >> N >> Q >> R >> P[0] >> P[1];
        
        int64 aR[2];
        int64 ax[2];
        for (int p = 0; p < 2; ++p) { aR[p] = R % P[p]; ax[p] = 1LL; }
            
        for (int i = 1; i <= N; ++i) { 
            cin >> seq[i];
            for (int p = 0; p < 2; ++p) {
                ax[p] *= aR[p]; ax[p] %= P[p];
                Ri[p][i] = (Ri[p][i-1] + ax[p]) % P[p];
                iRi[p][i] = (iRi[p][i-1] + (((int64(i)%P[p])*ax[p])%P[p])) % P[p];
                invRi[p][i] = fpw(ax[p],P[p]-2LL,P[p]);
            }
        }
        build(0,1,N);
        
        while (Q--) {
            cin >> cmd;
            switch(cmd) {
                case 0:
                    cin >> S >> D >> X >> Y;
                    for (int p = 0; p < 2; ++p) {
                        incA[p] = ((D%P[p]) * invRi[p][X])%P[p]; 
                        incB[p] = (subtract(S, int64(X)*D, P[p]) * invRi[p][X]) % P[p];
                    }
                    update(0,1,N);
                break;
                case 1:
                    cin >> X >> g;
                    update2(0,1,N);
                break;
                case 2:
                    cin >> X >> Y;
                    cout << get(0,1,N) << "\n";
                break;
            }
        }    
        
    }

	return 0;
}

















