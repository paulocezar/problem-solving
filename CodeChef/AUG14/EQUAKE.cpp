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

int lazy[1<<21];

short a[1<<20];        
short maxwith[1<<21][12];

void build(int node, int lo, int hi) {
    lazy[node] = 0;
    if (lo == hi) {
        short ax = a[lo];
        short pw = 1;
        while (ax / 10) {
            pw *= 10;
            ax /= 10;
        } 
        ax = a[lo];
        for (int i = 0; i < 12; ++i) {
            maxwith[node][i] = ax;
            ax = 10*(ax%pw) + (ax/pw);
        }
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        for (int i = 0; i < 12; ++i) {
            maxwith[node][i] = max(maxwith[ls][i], maxwith[rs][i]);
        }
    }
}

int aax[12];
void push(int node, bool leaf) {
    lazy[node] %= 12;
    if (!lazy[node]) return;
    if (!leaf) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        lazy[ls] += lazy[node];
        lazy[rs] += lazy[node];
    }
    for (int i = 0, j = lazy[node]; i < 12; ++i, ++j) {
        if (j == 12) j = 0;
        aax[i] = maxwith[node][j];
    }
    for (int i = 0; i < 12; ++i) maxwith[node][i] = aax[i];
    lazy[node] = 0;    
}

int from, to, f;
void update(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
        lazy[node] += f;
        push(node,lo==hi);
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        lazy[ls] += lazy[node];
        lazy[rs] += lazy[node];
        if (mid >= from) update(ls,lo,mid); else push(ls,lo==mid);
        if (mid < to) update(rs,mid+1,hi); else push(rs,(mid+1)==hi);
        lazy[node] = 0;
        for (int i = 0; i < 12; ++i) {
            maxwith[node][i] = max(maxwith[ls][i], maxwith[rs][i]);
        }
    }
}        
 
short get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
        push(node, lo==hi);
        return maxwith[node][0];
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        lazy[ls] += lazy[node];
        lazy[rs] += lazy[node];
        int a1 = 0, a2 = 0;
        if (mid >= from) a1 = get(ls,lo,mid); else push(ls,lo==mid);
        if (mid < to) a2 = get(rs,mid+1,hi); else push(rs,(mid+1)==hi);
        for (int i = 0; i < 12; ++i) {
            maxwith[node][i] = max(maxwith[ls][i], maxwith[rs][i]);
        }
        lazy[node] = 0;
        return max(a1,a2);
    }
}      

inline int next_short() {
    short res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}


inline int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}
        
int main(int argc, char* argv[]) {
	
    int N, M, cmd;
    
    N = next_int();
    for (int i = 0; i < N; ++i) a[i] = next_short();
    
    build(0,0,N-1);
    
    M = next_int();
    
    while (M--) {
        cmd = next_int();
        switch (cmd) {
            case 0: 
                    from = next_int();
                    to = next_int();
                    f = next_int();
                    update(0,0,N-1);
                    break;
            case 1: 
                    from = next_int();
                    to = next_int();
                    printf("%d\n", get(0,0,N-1));
                    break;
        }
    }

	return 0;
}
















