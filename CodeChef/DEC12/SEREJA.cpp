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

const int64 mod = 1000000007LL;

#define MAXN 100000
int a[MAXN];

/*
#define LGMN 17
int segt[1<<(LGMN+1)];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        segt[node] = lo;
    } else {
        int ls = (node<<1) + 1;
        int rs = ls+1;
        int mid = (lo+hi)>>1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        segt[node] = max(segt[ls], segt[rs]);   
    }
}
*/

int main(int argc, char* argv[]) {
	
    int n = next_int();
    
    REP(i, n) a[i] = next_int();
    
    REP(i, n-1) if (a[i] == a[i+1]) {
        puts("0"); return 0;
    }
    
    set<int> xx;
    bool repeated = false;
    REP(i, n) if (!xx.insert(a[i]).second) { repeated = true; break; }
    assert(!repeated);
    
    /*
    map<int, vector<int> > isat;
    bool repeated = false;
    REP(i, n) {
        if (!repeated && isat.count(a[i])) repeated = true;
        isat[ a[i] ].PB(i);     
    }
    */
    
    int64 res = 1;
    
    int cnt = 0;
    REP(i, n) {
        int mx = a[i];
        int lo = i-1;
        int hi = i+1;
        
        bool tolft, torgt;
        do {
            if (0 <= lo && a[lo] > a[i]) tolft = true; else tolft = false;
            if (hi < n && a[hi] > a[i]) torgt = true; else torgt = false;
            
            if (tolft && torgt) {
                if (a[lo] < a[hi]) {
                    mx = max(mx, a[lo]); lo--;    
                } else  {
                    mx = max(mx, a[hi]); hi++;
                }
            } else if (tolft) {
                mx = max(mx, a[lo]); lo--;
            } else if (torgt) {
                mx = max(mx, a[hi]); hi++;    
            }
            if (tolft || torgt) {
                res = (res * (int64(mx - a[i])%mod))%mod;
                cnt++;
            }
        } while ((tolft || torgt) && res);   
    }
        
    printf("%d\n", int(res)); 
	return 0;
}

















