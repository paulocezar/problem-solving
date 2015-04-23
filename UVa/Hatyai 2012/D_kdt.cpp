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

int tree[1<<19], val[1<<19], split[1<<19];

#define MAXN 200000
int x[MAXN], y[MAXN], id[MAXN];

inline bool compx(int a, int b) {
    return x[a] < x[b];
}

inline bool compy(int a, int b) {
    return y[a] < y[b];
}

void build(int node, int lo, int hi, bool xx) {   
    tree[node] = -1;
    
    if (lo == hi) {
        tree[node] = id[lo];
        val[node] = 1;
        return;
    }
    
    int mid = (lo+hi)/2;
    nth_element(id+lo, id+mid, id+hi+1, (xx ? compx : compy));
    split[node] = (xx ? x[id[mid]]: y[id[mid]]);
    
    int ls = (node<<1) + 1;
    int rs = ls+1;
    build(ls, lo, mid, !xx);
    build(rs, mid+1, hi, !xx);
    val[node] = val[ls] + val[rs];
}

int ax, ay, bx, by;
int query(int node, int xa = 0, int xb = INF, int ya = 0, int yb = INF, bool xx = true) {

    if (ax <= xa && xb <= bx && ay <= ya && yb <= by) return val[node];
    
    if (tree[node] != -1) {
        return ((ax <= x[tree[node]] && x[tree[node]] <= bx
                && ay <= y[tree[node]] && y[tree[node]] <= by) ? val[node] : 0); 
    }
    
    int res = 0;
    int ls = (node<<1) + 1;
    int rs = ls+1;
        
    if (xx) {
        if (ax <= split[node])
            res += query(ls, xa, split[node], ya, yb, !xx);
        if (split[node]+1 <= bx)
            res += query(rs, split[node]+1, xb, ya, yb, !xx);   
    } else {
        if (ay <= split[node])
            res += query(ls, xa, xb, ya, split[node], !xx);
        if (split[node]+1 <= by)
            res += query(rs, xa, xb, split[node]+1, yb, !xx);
    }
    
    return res;       
}

int main(int argc, char* argv[]) {
	
    int n, R1, R2, q, d1, d2, both, out, tc = 1;
    n = next_int();
    
    while (n) {
        REP(i,n) {
            x[i] = next_int();
            y[i] = next_int();
        }
    
        ax = next_int();
        ay = next_int();
        bx = next_int();
        by = next_int();
        q = next_int();
        
        REP(i,n) {
            d1 = (ax-x[i])*(ax-x[i]) + (ay-y[i])*(ay-y[i]);
            d2 = (bx-x[i])*(bx-x[i]) + (by-y[i])*(by-y[i]);
            
            x[i] = d1;
            y[i] = d2;
            id[i] = i;
        }
        
        build(0,0,n-1,true);
        
        REP(qq,q) {
            R1 = next_int();
            R2 = next_int();
            R1 *= R1;
            R2 *= R2;
            
            ax = R1+1, bx = INF, ay = R2+1, by = INF;
            out = query(0);
            
            ax = 0, bx = R1, ay = 0, by = R2;
            both = query(0);
            
            id[qq] = max(0, out-both);
        }
        
        printf("Case %d:\n", tc);
        REP(qq,q) printf("%d\n", id[qq]);
        
        tc++;
        n = next_int();
    }
    
	 
	return 0;
}

















