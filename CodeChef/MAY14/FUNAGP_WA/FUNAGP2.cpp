/* 

X <= i <= Y
A[i] += (S + (i-X) * D) * R^(i-X)
        (S + i*D - X*D) * R^(i-X)    
        (i*D + (S - X*D)) * R^i * R^-X
        R^i * (i*D*R^-X + (S - X*D)*R^-X)
        
        R^i * (i * A + B)
        
        A = D*R^-X
        B = (S - X*D)*R^-X
        
        
        R^i * (i * A + B)
        A * sum(R^i * i) +  B * sum(R^i)

*/
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

namespace P1 {
    int64 mod, sumReX[MAXN], invReX[MAXN], sumXReX[MAXN];
    int64 fpw(int64 a, int64 b) {
        int64 res = 1LL; a %= mod;
        while (b) {
            if (b & 1LL) { res *= a; res %= mod; }
            a *= a; a %= mod;
            b >>= 1;
        }
        return res;
    }
    int64 subtract(int64 a, int64 b) { return ((a%mod)-(b%mod)+mod)%mod;  }
    int64 srex(int a, int b) {
        return subtract(sumReX[b],sumReX[a-1]);
    }
    int64 sxrex(int a, int b) {
        return subtract(sumXReX[b],sumXReX[a-1]);
    }
};

namespace P2 {
    int64 mod, ReX[MAXN], invReX[MAXN];
    int64 fpw(int64 a, int64 b) {
        int64 res = 1LL; a %= mod;
        while (b) {
            if (b & 1LL) { res *= a; res %= mod; }
            a *= a; a %= mod;
            b >>= 1;
        }
        return res;
    }
    int64 subtract(int64 a, int64 b) { return ((a%mod)-(b%mod)+mod)%mod;  }
};

int64 A[MAXN];

int X, Y, g;
int64 incA1, incB1, incA2, incB2;

struct node_t {
    int64 A1, A2, B1, B2, sum, val;
    char need;
    bool lazy() { return need; }
};

node_t tree[1<<19];

void build(int node, int lo, int hi) {
    tree[node].A1 = tree[node].B1 = tree[node].A2 = tree[node].B2 = tree[node].sum = tree[node].val = 0LL;
    tree[node].need = 0;
    if (lo == hi) {
        tree[node].sum = A[lo] % P1::mod;
        tree[node].val = A[lo] % P2::mod;
    } else {
        int mid = (lo + hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        tree[node].sum = (tree[ls].sum + tree[rs].sum)%P1::mod;
    }
}

void propagate(int node, int lo, int hi) {
    if (lo != hi) {
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        tree[ls].A1 += tree[node].A1; tree[ls].A1 %= P1::mod;
        tree[ls].B1 += tree[node].B1; tree[ls].B1 %= P1::mod;
        tree[rs].A1 += tree[node].A1; tree[rs].A1 %= P1::mod;
        tree[rs].B1 += tree[node].B1; tree[rs].B1 %= P1::mod;
        tree[ls].A2 += tree[node].A2; tree[ls].A2 %= P2::mod;
        tree[ls].B2 += tree[node].B2; tree[ls].B2 %= P2::mod;
        tree[rs].A2 += tree[node].A2; tree[rs].A2 %= P2::mod;
        tree[rs].B2 += tree[node].B2; tree[rs].B2 %= P2::mod;
        tree[ls].need = 1; tree[rs].need = 1;
    }
    
    tree[node].sum += (((tree[node].A1 * P1::sxrex(lo,hi))%P1::mod) + ((tree[node].B1 * P1::srex(lo,hi))%P1::mod))%P1::mod;
    tree[node].sum %= P1::mod;
    
    if (lo == hi) {
        tree[node].val += (P2::ReX[lo] * (((((int64(lo)%P2::mod)*tree[node].A2)%P2::mod) + tree[node].B2)%P2::mod))%P2::mod;
        tree[node].val %= P2::mod;
    }
    tree[node].need = 0;
    tree[node].A1 = tree[node].B1 = tree[node].A2 = tree[node].B2 = 0LL;
}

void update(int node, int lo, int hi) {
    if (tree[node].lazy()) propagate(node, lo, hi);
    if ((X > hi) || (Y < lo)) return;
    if ((X <= lo) && (hi <= Y)) {
        tree[node].A1 += incA1; tree[node].A1 %= P1::mod;
        tree[node].B1 += incB1; tree[node].B1 %= P1::mod;
        tree[node].A2 += incA2; tree[node].A2 %= P2::mod;
        tree[node].B2 += incB2; tree[node].B2 %= P2::mod;
        propagate(node, lo, hi);
    } else {
        int mid = (lo + hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        update(ls,lo,mid);
        update(rs,mid+1,hi);
        tree[node].sum = (tree[ls].sum + tree[rs].sum)%P1::mod;
    }
}

void update2(int node, int lo, int hi) {
    
    if (tree[node].lazy()) propagate(node, lo, hi);
    
    if ((X > hi) || (X < lo)) return;
    
    if (lo == hi) {
        tree[node].val = P2::fpw(tree[node].val,g);
        tree[node].sum = tree[node].val % P1::mod;
    } else {
        int mid = (lo + hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        update2(ls,lo,mid);
        update2(rs,mid+1,hi);
        tree[node].sum = (tree[ls].sum + tree[rs].sum)%P1::mod;
    }
}

int64 get(int node, int lo, int hi) {
    if (tree[node].lazy()) propagate(node, lo, hi);
    if ((X > hi) || (Y < lo)) return 0LL;
    if ((X <= lo) && (hi <= Y)) {
        return tree[node].sum;
    } else {
        int mid = (lo + hi)>>1;
        int ls = (node<<1) + 1;
        int rs = (node<<1) + 2;
        int64 ret = 0LL;
        ret += get(ls,lo,mid);
        ret += get(rs,mid+1,hi);
        return (ret % P1::mod);
    }
}



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N, Q, cmd;
    int64 R, S, D;
    
    P1::sumReX[0] = 0LL;
    P1::sumXReX[0] = 0LL;
    
    cin >> T;
    while (T--) {
        cin >> N >> Q >> R >> P1::mod >> P2::mod;
        
        int64 R1 = R % P1::mod;
        int64 R2 = R % P2::mod;
        int64 ax1 = 1LL, ax2 = 1LL;
        
        
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            ax1 *= R1; ax1 %= P1::mod;
            ax2 *= R2; ax2 %= P2::mod;
            
            P1::sumReX[i] = P1::sumReX[i-1] + ax1;
            P1::invReX[i] = P1::fpw(ax1, P1::mod-2LL);
            P1::sumXReX[i] = (P1::sumXReX[i-1] + (((int64(i)%P1::mod) * ax1) % P1::mod))%P1::mod;
            
            P2::ReX[i] = ax2;
            P2::invReX[i] = P2::fpw(ax2, P2::mod-2LL);
        }
        
        build(0,1,N);
        
        while (Q--) {
            cin >> cmd;
            switch(cmd) {
                case 0:
                    cin >> S >> D >> X >> Y;
                    incA1 = ((D%P1::mod)*P1::invReX[X])%P1::mod;
                    incB1 = (P1::subtract(S, int64(X)*D)*P1::invReX[X])%P1::mod;
                    incA2 = ((D%P2::mod)*P2::invReX[X])%P2::mod;
                    incB2 = (P2::subtract(S, int64(X)*D)*P2::invReX[X])%P2::mod;                        
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

















