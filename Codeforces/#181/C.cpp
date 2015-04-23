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

const int64 mod = 1000000007LL;

int64 fat[1000001];
int64 ifat[1000001];

int64 C(int n, int k) {
    return (((fat[n] * ifat[n-k])%mod) * ifat[k]) % mod;
}

int64 fpw(int64 a, int b) {
    int64 res = 1;
    while (b) {
        if (b & 1) {
            res *= a; res %= mod; 
        }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int a, b, n;
    cin >> a >> b >> n;
    
    fat[0] = 1LL;
    ifat[0] = 1LL;
    FOR(i,1,n) {
        fat[i] = fat[i-1] * int64(i);
        if (fat[i] >= mod) fat[i] %= mod;
        ifat[i] = fpw(fat[i],mod-2);
    }
    
    int64 res = 0LL;
    for (int as = 0; as <= n; ++as) {
        int bs = n - as;
        int digitsum = as * a + bs * b;
        
        bool good = true;
        while (digitsum) {
            int dig = digitsum % 10;
            if (dig != a && dig != b) {
                good = false;
                break;
            } 
            digitsum /= 10;
        }
        if (good) {
            res += C(n, as);
            if (res >= mod) res -= mod;
        }
    }
    cout << res << "\n";
    
	return 0;
}

















