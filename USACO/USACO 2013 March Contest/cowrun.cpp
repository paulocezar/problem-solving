/*
ID: knightp2
PROG: cowrun
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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1024
int n, x[MAXN];

int cached[2][MAXN][MAXN];
int cache[2][MAXN][MAXN];

int solve(int lo, int hi, int l) {
    int len = (hi-lo+1);
    if (len == n) return 0;
    
    int &res = cache[l][lo][hi];
    if (cached[l][lo][hi]) return res;
    cached[l][lo][hi] = 1;
    res = 2e9;
    
    if (l) {
        if (lo) res = (n-len)*abs(x[lo]-x[lo-1]) + solve(lo-1,hi,1);
        if (hi+1 < n) res = min(res, (n-len)*abs(x[lo]-x[hi+1]) + solve(lo,hi+1,0));
    } else {
        if (hi+1<n) res = (n-len)*abs(x[hi]-x[hi+1]) + solve(lo,hi+1,0);
        if (lo) res = min(res, (n-len)*abs(x[hi]-x[lo-1]) + solve(lo-1,hi,1));
    }
    
    return res;
}

int main(int argc, char* argv[]) {
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    
    cin >> n;
    REP(i, n) cin >> x[i];
    sort(x,x+n);
    
    int res;
    
    if (x[n-1] < 0) {
        res = 0; REP(i, n) res -= x[i];
    } else if (x[0] > 0) {
        res = 0; REP(i, n) res += x[i];
    } else {
        int mid = 0;
        while (x[mid+1] < 0) mid++;
        
        int o1 = n*x[mid+1] + min(solve(mid+1,mid+1,0),solve(mid+1,mid+1,1));
        int o2 = -n*x[mid]  + min(solve(mid,mid,0),solve(mid,mid,1));
        res = min(o1, o2);
    }
    cout << res << "\n";
	return 0;
}




    










