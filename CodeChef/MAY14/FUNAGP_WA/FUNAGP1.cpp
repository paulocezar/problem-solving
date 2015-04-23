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

#define MAXN 100100

int64 fpow(int64 a, int b, int64 mod) {
    int64 res = 1LL;
    a %= mod;
    while (b) {
        if (b & 1) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int64 iRi1[MAXN], Ri1[MAXN], R_x1[MAXN], A[MAXN];
int64             Ri2[MAXN], R_x2[MAXN];


int64 S1[1<<19], S2[1<<19], D1[1<<19], D2[1<<19], A1[1<<19], A2[1<<19];
char lazy[1<<19];

int64 P1, P2;

void build(int node, int lo, int hi) {
    S1[node] = S2[node] = D1[node] = D2[node] = 0LL;
    lazy[node] = 0;
    if (lo == hi) {
        A1[node] = (A[lo] % P1);
        A2[node] = (A[lo] % P2);
    } else {
        int mid = (lo + hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls, lo, mid);
        build(rs,mid+1, hi);
        A1[node] = (A1[ls] + A1[rs]) % P1;
    }
}

int X, Y, g;
int64 NS1, ND1, NS2, ND2;

int64 modminus(int64 a, int64 b, int64 mod) { return ((((a%mod) - (b%mod))%mod) + mod)%mod; }

void propagate(int node, int lo, int hi) {
    
    if (lo != hi) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        S1[ls] += S1[node]; S1[ls] %= P1;  S1[rs] += S1[node]; S1[rs] %= P1;  
        D1[ls] += D1[node]; D1[ls] %= P1;  D1[rs] += D1[node]; D1[rs] %= P1;
        S2[ls] += S2[node]; S2[ls] %= P2;  S2[rs] += S2[node]; S2[rs] %= P2;
        D2[ls] += D2[node]; D2[ls] %= P2;  D2[rs] += D2[node]; D2[rs] %= P2;
        lazy[ls] = lazy[rs] = 1;
    }
    
    A1[node] += (((S1[node] * modminus(iRi1[hi], iRi1[lo-1], P1))%P1) + ((D1[node] * modminus(Ri1[hi], Ri1[lo-1], P1))%P1))%P1;
    A1[node] %= P1;
    
    if (lo == hi) {
        A2[node] += (Ri2[lo] * ((((S2[node] * lo)%P2)  + D2[node])%P2))%P2;
        A2[node] %= P2;
    }
    lazy[node] = 0;
    S1[node] = D1[node] = S2[node] = D2[node] = 0LL;    
}

void update(int node, int lo, int hi) {
    
    if (lazy[node]) propagate(node, lo, hi);
    
    if ((Y < lo) || (X > hi)) return;
    
    if ((X <= lo) && (hi <= Y)) {
        S1[node] += NS1; S1[node] %= P1;
        D1[node] += ND1; D1[node] %= P1;
        S2[node] += NS2; S2[node] %= P2;
        D2[node] += ND2; D2[node] %= P2;
        propagate(node, lo, hi);
    } else {
        int mid = (lo + hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        update(ls, lo, mid);
        update(rs, mid+1, hi);
        A1[node] = (A1[ls] + A1[rs]) % P1;
    }
}

void update2(int node, int lo, int hi) {
    
    if (lazy[node]) propagate(node, lo, hi);
    
    if ((X < lo) || (X > hi)) return;
    
    if ((lo == hi) && (lo == X)) {
        A2[node] = fpow(A2[node], g, P2);
        A1[node] = A2[node] % P1;
    } else {
        int mid = (lo + hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        update2(ls, lo, mid);
        update2(rs, mid+1, hi);
        A1[node] = (A1[ls] + A1[rs]) % P1;
    }
    
}


int64 query(int node, int lo, int hi) {
    
    if (lazy[node]) propagate(node, lo, hi);
    
    if ((X <= lo) && (hi <= Y)) return A1[node];
    
    int mid = (lo + hi)>>1;
    int ls = (node << 1) + 1;
    int rs = ls + 1;
    int64 ret = 0LL;
    
    if (X <= mid) ret += query(ls, lo, mid);
    if (Y > mid) ret += query(rs, mid+1, hi);

    return (ret % P1);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N, Q, cmd;
    int64 S, D, R;
    
    cin >> T;
    while (T--) {
        cin >> N >> Q >> R >> P1 >> P2;
        
        for (int i = 1; i <= N; ++i) cin >> A[i];
        
        iRi1[0] = 0LL, Ri1[0] = 1LL, R_x1[0] = 1LL;
                       Ri2[0] = 1LL, R_x2[0] = 1LL;
        
        int64 R1 = R % P1;
        int64 R2 = R % P2;
        int64 ax1 = 1LL;
        int64 ax2 = 1LL;
        
        for (int i = 1; i <= N; ++i) {
            
            ax1 *= R1; ax1 %= P1;
            ax2 *= R2; ax2 %= P2;
            
            iRi1[i] = (iRi1[i-1] + ((int64(i) * ax1)%P1)) % P1;
            Ri1[i] = (Ri1[i-1] + ax1) % P1;
            R_x1[i] = fpow(ax1, P1-2LL, P1);
            
            Ri2[i] = ax2;
            R_x2[i] = fpow(ax2, P2-2LL, P2);
        }
        
        build(0, 1, N);
        
        while (Q--) {
            cin >> cmd;
            switch (cmd) {
                case 0:
                    cin >> S >> D >> X >> Y;
                    NS1 = (D*R_x1[X])%P1;
                    ND1 = (modminus(S, D * int64(X), P1)*R_x1[X])%P1;
                
                    NS2 = (D*R_x2[X])%P2;
                    ND2 = (modminus(S, D * int64(X), P2)*R_x2[X])%P2;
                
                    update(0, 1, N);
                break;
                case 1:
                    cin >> X >> g;
                    update2(0, 1, N);
                break;    
                case 2:
                    cin >> X >> Y;
                    cout << query(0, 1, N) << "\n";
                break;
            }
        }
        
    }

	return 0;
}

















