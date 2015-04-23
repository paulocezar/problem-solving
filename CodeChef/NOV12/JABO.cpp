#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXV 500*2500

int pa[MAXV], rk[MAXV];
int vw[MAXV];

int find(int x) {
    int ax, px = x;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int px, int py) {
    px = find(px), py = find(py);
    if (px == py) return;
    if (rk[px]<rk[py]) swap(px,py);
    pa[py] = px;
    if (rk[px] == rk[py]) rk[px]++;
    vw[px] += vw[py];
}

char cmd[16];

inline int getval(char c) {
    if ('A' <= c && c <= 'Z') return (c-'A');
    return (26+c-'a');
}

int main(int argc, char* argv[]) {
	
	int N, R, C;
    scanf("%d %d %d", &N, &R, &C);
    
    REP(i,R*C) {
        pa[i] = i, rk[i] = 0, vw[i] = 0;
    }
    
    int xa, ya, xb, yb, va, vb;
    
    while (N--) {
        scanf("%s", cmd);
        switch(cmd[0]) {
            case 'W':
                ya = getval(cmd[1])*52 + getval(cmd[2]) - 1;
                xa = (getval(cmd[3])*52 + getval(cmd[4]) - 1)/5;
                yb = getval(cmd[5])*52 + getval(cmd[6]) - 1;
                xb = (getval(cmd[7])*52 + getval(cmd[8]) - 1)/5;
                va = xa*C + ya;
                vb = xb*C + yb;
                fUnion(va,vb);
                break;
            case 'V':
                ya = getval(cmd[1])*52 + getval(cmd[2]) - 1;
                xa = (getval(cmd[3])*52 + getval(cmd[4]) - 1)/5;
                va = xa*C + ya;
                vw[find(va)]++;
                break;
            case 'R':
                ya = getval(cmd[1])*52 + getval(cmd[2]) - 1;
                xa = (getval(cmd[3])*52 + getval(cmd[4]) - 1)/5;
                va = xa*C + ya;
                vw[find(va)]--;
                break;
            case 'L':
                ya = getval(cmd[1])*52 + getval(cmd[2]) - 1;
                xa = (getval(cmd[3])*52 + getval(cmd[4]) - 1)/5;
                yb = getval(cmd[5])*52 + getval(cmd[6]) - 1;
                xb = (getval(cmd[7])*52 + getval(cmd[8]) - 1)/5;
                va = xa*C + ya;
                vb = xb*C + yb;
                va = vw[find(va)] ? 1 : 0;
                vb = vw[find(vb)] ? 1 : 0;
                if (va != vb) puts("ON");
                else puts("OFF");
                break;
        }
    }
	
	return 0;
}

















