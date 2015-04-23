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
pair<int,int> a[MAXN], b[MAXN];
int64 m, ft[MAXN+1];

int occ[2*MAXN+1];
int pfact[2*MAXN+1];
vector<int> pr;

void sieve() {
    for (int i = 2; i <= 2*MAXN; ++i) {
        if (pfact[i] == 0) {
            pfact[i] = i;
            pr.PB(i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=pfact[i] && i*pr[j]<=2*MAXN; ++j)
        		pfact[i * pr[j]] = pr[j];
    }
}

void get(int n) {
    
    FOR(i,2,n) occ[i] = 1;
    
    RFOR(i,n,2) {
        if (pfact[i] != i) {
            int x = pfact[i];
            int y = i / pfact[i];
            int inc = occ[i];
            occ[x] += inc;
            occ[y] += inc;
            occ[i] = 0;
        }
    }
}

int64 fstpw(int64 a, int64 b) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) { res *= a; res %= m; }
        a *= a; a %= m;
        b >>= 1;
    }
    return res;
}

int64 calc(int n) {
    int64 res = 1LL;
    FOR(i,2,n) {
        if (occ[i]) {
            res *= fstpw(i,occ[i]);
            res %= m;
            occ[i] = 0;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();
    
    int n;
    cin >> n;
    
    REP(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    REP(i, n) {
        cin >> b[i].first;
        b[i].second = i;
    }
    
    cin >> m;
    
    ft[0] = 1LL;
    FOR(i,1,n) {
        ft[i] = int64(i % m) * ft[i-1];
        ft[i] %= m;
    }
    
    sort(a,a+n);
    sort(b,b+n);
    
    int ia = 0, ib = 0;
    int64 res = 1LL;
    
    while (ia < n && ib < n) {
        if (a[ia].first < b[ib].first) {
            int ii = ia;
            while (ii < n && a[ii].first == a[ia].first) ii++;
            res *= ft[ii-ia];
            res %= m;
            ia = ii;
        } else if (b[ib].first < a[ia].first){
            int ii = ib;
            while (ii < n && b[ii].first == b[ib].first) ii++;
            res *= ft[ii-ib];
            res %= m;
            ib = ii;
        } else {
            int len = 0;
            int ii = ia;
            tr1::unordered_set<int> dd;
            
            while (ii < n && a[ii].first == a[ia].first) {
                dd.insert(a[ii].second);
                ii++;
                len++;
            }
            ia = ii;
            ii = ib;
            int rem = 0;
            while (ii < n && b[ii].first == b[ib].first) {
                if (!dd.insert(b[ii].second).second) rem++;
                ii++;
                len++;
            }
            ib = ii;
            get(len);
            occ[2] -= rem;
            res *= calc(len);
            res %= m;
        }           
    }
    
    while (ia < n) {
        int ii = ia;
        while (ii < n && a[ii].first == a[ia].first) ii++;
        res *= ft[ii-ia];
        res %= m;
        ia = ii;
    } 
    
    while (ib < n){
        int ii = ib;
        while (ii < n && b[ii].first == b[ib].first) ii++;
        res *= ft[ii-ib];
        res %= m;
        ib = ii;
    }
    
    cout << res << "\n";
    
	return 0;
}

















