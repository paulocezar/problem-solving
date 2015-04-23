/*
ID: knightp2
PROG: seating
LANG: C++
*/
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
#include <fstream>
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

int pft[1<<20];
int sft[1<<20];
int mxt[1<<20];
int lazy[1<<20];

void build(int node, int lo, int hi) {
    lazy[node] = 0;
    if (lo == hi) {
        pft[node] = 1;
        sft[node] = 1;
        mxt[node] = 1;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        mxt[node] = max(mxt[ls], mxt[rs]);
        mxt[node] = max(mxt[node], sft[ls]+pft[rs]);
        pft[node] = pft[ls];
        if (pft[ls] == (mid-lo+1)) pft[node] += pft[rs];
        sft[node] = sft[rs];
        if (sft[rs] == (hi-mid)) sft[node] += sft[ls];
        mxt[node] = max(mxt[node], max(sft[node], pft[node]));
    }
}

inline void push(int node, int len) {
    if (len > 1) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        lazy[ls] = lazy[node];
        lazy[rs] = lazy[node];
    }
    if (lazy[node] == 1) {
        mxt[node] = pft[node] = sft[node] = len;
    } else {
        mxt[node] = pft[node] = sft[node] = 0;
    }
    lazy[node] = 0;
}

int getmax(int node, int lo, int hi) {
   if (lazy[node]) push(node, hi-lo+1);
   return mxt[node];
}

void sit(int node, int lo, int hi, int amnt, int leftm) {
    int len = hi-lo+1;
    if (lazy[node]) push(node, len);
    if (len == amnt) {
        lazy[node] = 2; push(node, len);
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        if (leftm) {
            int justleft = getmax(ls,lo,mid);
            if (justleft >= amnt) {
                sit(ls,lo,mid,amnt,leftm);
            } else {
                if (sft[ls]) {
                    amnt -= sft[ls];
                    sit(ls,lo,mid,sft[ls],0);
                    sit(rs,mid+1,hi,amnt,1);
                } else {
                    sit(rs,mid+1,hi,amnt,leftm);
                }
            }
        } else {
            if (lazy[rs]) push(rs,hi-mid);
            if (sft[rs] >= amnt) {
                sit(rs,mid+1,hi,amnt,leftm);
            } else {
                amnt -= sft[rs];
                sit(rs,mid+1,hi,sft[rs],leftm);
                sit(ls,lo,mid,amnt,leftm);
            }
        }
        if (lazy[ls]) push(ls,mid-lo+1);
        if (lazy[rs]) push(rs,hi-mid);
       
        mxt[node] = max(mxt[ls], mxt[rs]);
        mxt[node] = max(mxt[node], sft[ls]+pft[rs]);
        pft[node] = pft[ls];
        if (pft[ls] == (mid-lo+1)) pft[node] += pft[rs];
        sft[node] = sft[rs];
        if (sft[rs] == (hi-mid)) sft[node] += sft[ls];
        mxt[node] = max(mxt[node], max(sft[node], pft[node]));
    }
}

int from, to;
void release(int node, int lo, int hi) {
    if (lazy[node]) push(node, hi-lo+1);
    if (from <= lo && hi <= to) {
        lazy[node] = 1; push(node,hi-lo+1);
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (mid >= from) release(ls,lo,mid);
        if ((mid+1) <= to) release(rs,mid+1,hi);
        if (lazy[ls]) push(ls,mid-lo+1);
        if (lazy[rs]) push(rs,hi-mid);

        mxt[node] = max(mxt[ls], mxt[rs]);
        mxt[node] = max(mxt[node], sft[ls]+pft[rs]);
        pft[node] = pft[ls];
        if (pft[ls] == (mid-lo+1)) pft[node] += pft[rs];
        sft[node] = sft[rs];
        if (sft[rs] == (hi-mid)) sft[node] += sft[ls];
        mxt[node] = max(mxt[node], max(sft[node], pft[node]));
    }
}

int main(int argc, char* argv[]) {
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
    
    int N, M;
    cin >> N >> M;
    
    build(0,0,N-1);

    int res = 0, p, freespots;
    while (M--) {
        char wut; cin >> wut;
        switch (wut) {
            case 'A':
                cin >> p;
                freespots = getmax(0,0,N-1);
                if (freespots >= p) {
                    sit(0,0,N-1,p,1);
                } else {
                    res++;
                }
            break;
            case 'L':
                cin >> from >> to; from--, to--;
                release(0,0,N-1);
            break;
        }
    }
    cout << res << "\n";
        
	return 0;
}

















