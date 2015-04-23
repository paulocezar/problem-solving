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

#define MAXN 200000
int64 segt[1<<19];
int64 a[MAXN];
int64 w[MAXN];

int from, to;
void push(int node, int len) {
    if (segt[node] && len > 1) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        segt[ls] += segt[node];
        segt[rs] += segt[node];
        segt[node] = 0;
    }
}

void add(int node, int lo, int hi) {
    push(node, hi-lo+1);
    if (hi < from || lo > to) return;
    if (from <= lo && hi <= to) {
        segt[node]++; push(node,hi-lo+1);
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        add(ls,lo,mid);
        add(rs,mid+1,hi);
    }
}

int64 get(int node, int lo, int hi) {
    push(node,hi-lo+1);
    if (lo == hi) return segt[node];
    int mid = (lo+hi)>>1;
    if (from <= mid) return get((node<<1)+1, lo, mid);
    return get((node<<1)+2,mid+1,hi);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    REP(i, n) cin >> a[i];
    while (q--) {
        cin >> from >> to; from--; to--;
        add(0,0,n-1);
    }
    REP(i, n) {
        from = i;
        w[i] = get(0,0,n-1);
    }
    sort(a,a+n);
    sort(w,w+n);
    int64 res = 0LL;
    REP(i,n) res += a[i]*w[i];
    cout << res << "\n";
	return 0;
}

















