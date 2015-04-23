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

int dg[1024];
int chn[1024];
int blocked[1024];

int n, k, m;

int pressup(int at) {
    if (at == -1) return 2e9;
    at++; if (at > n) at = 1;
    while (blocked[at]) { at++; if (at > n) at = 1; }
    return at;
}

int pressdw(int at) {
    if (at == -1) return 2e9;
    at--; if (at < 1) at = n;
    while (blocked[at]) { at--; if (at < 1) at = n; }
    return at;
}

set<int64> active;
map<int64, int> res;

int go(int pos, int cur, int prv, int pp) {   
    
    if (pos == m) return 0;
    if (cur == chn[pos]) return go(pos+1, cur, prv, pp);
    
    int64 vv = 2LL*(1001LL*(1001LL*pos + cur)+prv) + pp;
    if (!active.insert(vv).second) return 2e9;
    if (res.count(vv)) {
        active.erase(vv);
        return res[vv];
    }
    
    int pu = pressup(cur);
    int pd = pressdw(cur);
    
    int a = (pu != cur) ? (1 + go(pos, pu, cur, 0)) : 2e9;
    int b = (pd != cur) ? (1 + go(pos, pd, cur, 0)) : 2e9;
    int c = ((!pp && (prv != cur)) ? (1 + go(pos, prv, cur, 1)) : 2e9);
    int d = 2e9;
    FOR(i, 1, n) if (!blocked[i]) {
        if (i == cur) continue;
        d = min(d, dg[i] + go(pos,i,cur, 0));
    }
    
    res[vv] = min(a, min(b,min(c,d)));
    active.erase(vv);
    return res[vv];
}



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
        
    FOR(i,1,1000) {
        dg[i] = 0;
        int x = i;
        while (x) {
            dg[i]++;
            x /= 10;
        }
    }
    
    int t;
    cin >> t;
    FOR(kase,1,t) {
        
        cin >> n >> k;
        
        FOR(i,1,n) blocked[i] = 0;
        
        REP(i, k) {
            int bb; cin >> bb;
            blocked[bb] = 1;
        }
        
        cin >> m;
        REP(i, m) cin >> chn[i];
        int res = dg[chn[0]]+ go(1,chn[0],chn[0],0);
        
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
	return 0;
}

















