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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 2014

struct rpouch {
    int64 v, u, l;
    rpouch(int64 vv = 0, int64 uu = 0, int64 ll = 0) : v(vv), u(uu), l(ll) {}
    bool operator < (const rpouch &t) const {
        if (v != t.v) return v < t.v;
        if (u != t.u) return u < t.u;
        return l < t.l;
    }
} retort[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        REP(i, n) {
            cin >> retort[i].v  >> retort[i].u >> retort[i].l;
        }
        sort(retort, retort+n);
        
        int64 day = 1;
        int64 res = 0;
        bool xtra = false;
        
        REP(i, n) {
            
            int64 due = min(retort[i].u, day+retort[i].l-1LL);
            int64 odue = min(retort[i].u, day+retort[i].l-2LL);
            
            if (xtra) due = odue;
            
            if (day > due) {
                res += retort[i].v;
            } else {
                if (xtra) retort[i].v--;
                
                int64 days = due-day+1LL;
                int64 ndd = ((retort[i].v+1LL) / 2LL);
    
                if (ndd > days) {
                    res += (retort[i].v - days * 2LL);
                    xtra = false;
                    day += days;
                } else {
                    if (retort[i].v & 1LL) xtra = true;
                    else xtra = false;
                    day += ndd;
                }
                
            }
            
        }
        cout << res << "\n";
    }
	 
	return 0;
}

















