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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

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

#define MAXN 100000
#define LGN 17

bitset< (1<<(LGN+1)) > incr, decr;
int segt[1<<(LGN+1)];

int a[MAXN];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        incr[node] = 1;
        decr[node] = 1;
        segt[node] = lo;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        incr[node] = incr[ls] && (a[mid] <= a[mid+1]) && incr[rs];
        decr[node] = decr[ls] && (a[mid] >= a[mid+1]) && decr[rs];
        if (a[segt[ls]] > a[segt[rs]]) segt[node] = segt[ls];
        else segt[node] = segt[rs];
    }
}

int from, to;
int get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return segt[node];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (mid+1 > to) return get(ls,lo,mid);
        if (mid < from) return get(rs,mid+1,hi);
        int a1 = get(ls,lo,mid);
        int a2 = get(rs,mid+1,hi);
        if (a[a1] > a[a2]) return a1;
        return a2;
    }
}

bool increase(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return incr[node];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (mid+1 > to) return increase(ls,lo,mid);
        if (mid < from) return increase(rs,mid+1,hi);
        return increase(ls,lo,mid) && (a[mid] <= a[mid+1]) && increase(rs,mid+1,hi);
    }
}

bool decrease(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return decr[node];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (mid+1 > to) return decrease(ls,lo,mid);
        if (mid < from) return decrease(rs,mid+1,hi);
        return decrease(ls,lo,mid) && (a[mid] >= a[mid+1]) && decrease(rs,mid+1,hi);
    }
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    build(0,0,n-1);
    
    int l, r;
    while (m--) {
        cin >> l >> r; l--, r--;
        
        from = l, to = r;
        int pmx = get(0,0,n-1);
        
        
        from = l, to = pmx;
        bool firsthf = increase(0,0,n-1);
        
        from = pmx, to  = r;
        bool scndhf = decrease(0,0,n-1);
        
        if (firsthf && scndhf) cout << "Yes\n";
        else cout << "No\n";
        
    }
    
	return 0;
}

















