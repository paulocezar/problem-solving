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

const int64 mod = 1000000007LL;

int64 fat[1001], ift[1001], f[1001];

int64 fastpw(int64 a, int b) {
    int64 res = 1LL;
    while (b) {
        if (b&1) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

inline int64 C(int n, int k) { return (((fat[n]*ift[k])%mod)*ift[n-k])%mod; }

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    fat[0] = ift[0] = 1LL;
    FOR(n, 1, 1000) {
        fat[n] = (int64(n) * fat[n-1])%mod;
        ift[n] = fastpw(fat[n], mod-2);
    }
    
    FOR(n, 1, 1000) {
        f[n] = 0;
        FOR(i,0,(n-1)/2) {
            f[n] += C(n,i);
            if (f[n] >= mod) f[n] -= mod;
        }
    }
    
    int t, n, trash;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, n) cin >> trash;
        cout << f[n] << "\n";
    }
    
	return 0;
}

















