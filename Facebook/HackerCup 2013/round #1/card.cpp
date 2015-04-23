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

int64 fstpw(int64 a, int64 b) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int64 f[10010];
int64 fi[10010];
int64 a[10010];

int64 comb(int n, int k) {
    if (n < k) return 0LL;
    return (((f[n]*fi[k])%mod)*fi[n-k])%mod;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    f[0] = 1LL;
    fi[0] = 1LL;
	 
    for (int i = 1; i <= 10000; ++i) {
        f[i] = (int64(i) * f[i-1]) % mod;
        fi[i] = fstpw(f[i], mod-2LL);
    }
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        int N, K;
        cin >> N >> K;
        REP(i, N) cin >> a[i];
        sort(a, a+N);
        int64 res = 0LL;
        REP(i, N) {
            res += ((a[i]%mod) * comb(i,K-1))%mod;
            res %= mod;
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }


	return 0;
}

















