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

#include <sys/resource.h>

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

#define MAXN 100001
int H[MAXN], id[MAXN], rid[MAXN], lst[MAXN];

int mn[1<<18], cnt[1<<18], lz[1<<18];

void build(int node, int lo, int hi) {
    lz[node] = 0;
    if (lo == hi) {
        mn[node] = H[rid[lo]];
        cnt[node] = 1;
    } else {
        int mid = (lo + hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        mn[node] = min(mn[ls], mn[rs]);
        cnt[node] = cnt[ls] + cnt[rs];
    }
}

void push(int node, int lo, int hi) {
    if (lz[node] < mn[node]) return;
    if (lo == hi) {
        mn[node] = 2e9;
        cnt[node] = 0;
    } else {
       int mid = (lo+hi)>>1;
       int ls = (node<<1) + 1;
       int rs = ls + 1;
       lz[ls] += lz[node];
       lz[rs] += lz[node];
       
       push(ls, lo, mid);
       push(rs, mid+1, hi);

       mn[node] = min(mn[ls]-lz[ls], mn[rs]-lz[rs]);
       cnt[node] = cnt[ls] + cnt[rs];
   }
   lz[node] = 0;
}

void prop(int node, int lo, int hi) {
    if (!lz[node]) return;
    if (lz[node] < mn[node]) {
        
        if (lo != hi) {

            int ls = (node<<1) + 1;
            int rs = ls + 1;
            lz[ls] += lz[node];
            lz[rs] += lz[node];
            lz[node] = 0;
            
            mn[node] = min(mn[ls]-lz[ls], mn[rs]-lz[rs]);
       }
       
    } else push(node, lo, hi);   
}

int from, to, val;
void update(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
        lz[node] += val;
        prop(node, lo, hi);
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        prop(node, lo, hi);
        prop(ls,lo,mid);
        prop(rs,mid+1,hi);
        
        if (mid >= from) update(ls, lo, mid);
        if ((mid+1) <= to) update(rs, mid+1, hi);
        
        mn[node] = min(mn[ls]-lz[ls], mn[rs]-lz[rs]);
        cnt[node] = cnt[ls] + cnt[rs];
    }    
}

int query(int node, int lo, int hi) {
    prop(node, lo, hi); 
    if (from <= lo && hi <= to) {
        return cnt[node];
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        int res = 0;
        if (mid >= from) res += query(ls,lo,mid);
        if ((mid+1) <= to) res += query(rs,mid+1,hi);
        return res;
    }
}

vector<int> gr[MAXN];

int dfsnum;
void dfs(int u) {
    id[u] = dfsnum;
    rid[dfsnum] = u; 
    dfsnum++;
    
    REP(i, SIZE(gr[u])) dfs(gr[u][i]);
    
    lst[u] = dfsnum-1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    //const rlim_t kStackSize = 256L * 1024L * 1024L;
    //struct rlimit rl; 
    //getrlimit(RLIMIT_STACK, &rl);
    //rl.rlim_cur = kStackSize;
    //setrlimit(RLIMIT_STACK, &rl);
        
    int N;
    cin >> N;
    
    FOR(i, 1, N) {
        int pa;
        cin >> H[i] >> pa;
        gr[pa].push_back(i);
    }
    
    dfsnum = 0;
    dfs(0);
    
    build(0,1,N);
    
    int Q;
    cin >> Q;
    while (Q--) {
        int cmd, u, x;
        cin >> cmd >> u;
        
        switch (cmd) {
            case 1 :
                    cin >> x;
                    from = id[u]+1, to = lst[u], val = x;
                    if (from <= to) update(0,1,N);
                    break;
            case 2 :
                    x = 0;
                    from = id[u]+1, to = lst[u];
                    if (from <= to) x = query(0,1,N);
                    cout << x <<  "\n";
                    break;
        }
    }
    
	return 0;
}

















