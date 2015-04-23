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
int v[MAXN];

int mx[1<<18], mn[1<<18];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        mx[node] = v[lo];
        mn[node] = v[hi];
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi)>>1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        mx[node] = max(mx[ls],mx[rs]);
        mn[node] = min(mn[ls],mn[rs]);
    }
}

int from, to;
int getmx(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return mx[node];
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;
    if (mid+1 > to) return getmx(ls,lo,mid);
    if (mid < from) return getmx(rs,mid+1,hi);
    return max(getmx(ls,lo,mid),getmx(rs,mid+1,hi));
}

int getmn(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return mn[node];
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    int mid = (lo+hi)>>1;
    if (mid+1 > to) return getmn(ls,lo,mid);
    if (mid < from) return getmn(rs,mid+1,hi);
    return min(getmn(ls,lo,mid),getmn(rs,mid+1,hi));
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    
    int N;
    cin >> N;
    REP(i,N) cin >> v[i];
    
    build(0,0,N-1);
    
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        from = L, to = R;
        int mmx = getmx(0,0,N-1);
        int mmn = getmn(0,0,N-1);
        
        double res = (mmx-mmn)/2.0 + mmn;
        
        from = 0, to = L-1;
        int maxa = (from <= to) ? getmx(0,0,N-1) : 0;
        res = max(res, .0 + maxa + mmn);
        
        from = R+1, to = N-1;
        int maxb = (from <= to) ? getmx(0,0,N-1) : 0;
        res = max(res, .0 + maxb + mmn);
        
        cout << res << "\n";
    }
    
    
	return 0;
}

















