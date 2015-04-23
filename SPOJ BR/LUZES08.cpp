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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int pa[10000], rk[10000], tcnt[10000];

int find(int x) {
    int ax, px = x;
    while (px != pa[px]) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    if (rk[px] < rk[py]) swap(px,py);
    pa[py] = px;
    if (rk[px] == rk[py]) rk[px]++;
    tcnt[px] += tcnt[py];
}


int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

int main( int argc, char* argv[] ){
    
    int L, B, st;
    L = next_int();
    B = next_int();
    
    REP(i,L) {
        st = next_int();
        pa[i] = i;
        tcnt[i] = st;
    }
    
    REP(i,L) {
        st = next_int();
        tcnt[i] ^= st;
    }
    
    int u, v;
    REP(i,B) {
        u = next_int();
        v = next_int();
        u--; v--;
        fUnion(u,v);
    }
    
    bool ok = true;
    REP(i,L) {
        if (pa[i] == i) {
            if (tcnt[i] & 1) { ok = false; break; }
        }
    }
    if (ok) puts("S");
    else puts("N");
    
    return 0;
}
















