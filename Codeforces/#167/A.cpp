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

int64 segt[1<<18];
int64 nval[1<<18];

int a[MAXN];

void build(int node, int lo, int hi) {
    if (lo ==hi) {
        segt[node] = a[lo];
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        segt[node] = max(segt[ls],segt[rs]);
    }
}

void push(int node, int len) {
    if (!nval[node]) return;
    if (len != 1) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        nval[ls] = nval[node];
        nval[rs] = nval[node];
    }
    segt[node] = nval[node];
    nval[node] = 0;
}

int from, to;
int64 put;

int64 get(int node, int lo, int hi) {
    push(node,hi-lo+1);
    if (from <= lo && hi <= to) return segt[node];
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;
    if (mid+1 > to) return get(ls,lo,mid);
    if (mid < from) return get(rs,mid+1,hi);
    return max(get(ls,lo,mid), get(rs,mid+1,hi));
}

void updt(int node, int lo, int hi) {
    push(node,hi-lo+1);
    if (lo > to || hi < from) return;
    if (from <= lo && hi <= to) {
        nval[node] = put;
        push(node,hi-lo+1);
        return;
    }
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;
    updt(ls,lo,mid);
    updt(rs,mid+1,hi);
    segt[node] = max(segt[ls], segt[rs]);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    REP(i,n) cin >> a[i];
    build(0,0,n-1);
    
    int m;
    cin >> m;
    REP(i, m) {
        int64 w, h; cin >> w >> h;
        from = 0; to = w-1;
        int64 mx = get(0,0,n-1);
        cout << mx << "\n";
        put = mx + h;
        updt(0,0,n-1);
    }

    
	return 0;
}

















