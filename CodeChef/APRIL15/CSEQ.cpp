#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 1000003LL;

int64 ft[MOD];

int64 fstpw(int64 a, int64 b) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) { res *= a; res %= MOD; }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}

int countFact(int n, int p) {
    int k = 0;
    while (n >= p) {
        k += n/p;
        n /= p;
    }
    return k;
}

int factMOD(int n) {
    int64 res = 1LL; 
    while (n > 0LL) {
        res = (res * ft[n%MOD]) % MOD;
        n /= MOD;
        if (n & 1LL) res = MOD - res;
    }
    return res;
}

int64 invMOD(int x) {
    return fstpw(x,MOD-2LL);
}

int64 C(int n, int r) {
    if (countFact(n, MOD) > (countFact(r, MOD) + countFact(n-r, MOD))) return 0LL;
 
    return (factMOD(n) *
            ((invMOD(factMOD(r)) * 
            invMOD(factMOD(n-r))) % MOD)) % MOD;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ft[0] = 1LL;
    ft[1] = 1LL;
    for (int64 i = 2; i < MOD; ++i) ft[i] = (i * ft[i-1]) % MOD;
    
    int T;
    cin >> T;
    while (T--) {
        int N, L, R, M;
        cin >> N >> L >> R;
        M = R-L+1LL;
        cout << (C(N+M, N) + MOD - 1LL)%MOD << "\n";
    }
    
	return 0;
}

















