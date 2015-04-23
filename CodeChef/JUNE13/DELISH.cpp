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

#define MAXN 10101

int64 d[MAXN];
int64 minuntil[MAXN];
int64 maxuntil[MAXN];
int64 minafter[MAXN];
int64 maxafter[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        FOR(i, 1, n) cin >> d[i];
        
        minuntil[0] = 2e9;
        maxuntil[0] = -2e9;
        minafter[n+1] = 2e9;
        maxafter[n+1] = -2e9;
        
        int64 mnsum = 0, mxsum = 0;
        FOR(i,1,n) {
            mnsum += d[i];
            mxsum += d[i];
            
            minuntil[i] = min(minuntil[i-1], mnsum);
            maxuntil[i] = max(maxuntil[i-1], mxsum);
            if (mxsum < 0) mxsum = 0;
            if (mnsum > 0) mnsum = 0;
        }
        
        mnsum = 0, mxsum = 0;
        RFOR(i,n,1) {
            mnsum += d[i];
            mxsum += d[i];
            
            minafter[i] = min(minafter[i+1], mnsum);
            maxafter[i] = max(maxafter[i+1], mxsum);
            if (mxsum < 0) mxsum = 0;
            if (mnsum > 0) mnsum = 0;
        }
        
        int64 ans = 0;
        FOR(i,1,n-1) {
            ans = max(ans, abs(minuntil[i] - maxafter[i+1]));
            ans = max(ans, abs(maxuntil[i] - minafter[i+1]));
        }
        cout << ans << "\n";
    }
    
    
	return 0;
}

















