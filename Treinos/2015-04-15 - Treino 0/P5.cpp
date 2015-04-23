#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;

int64 fpow(int64 a, int x) {
    int64 ret = 1LL;
    while (x) {
        if (x & 1) ret = (a * ret) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return ret;
}

int64 fat[512], ifat[512];

int64 C(int n, int k) {
    if (n < k) return 0LL;
    return (((fat[n] * ifat[n-k])%mod) * ifat[k]) % mod;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    fat[0] = ifat[0] = 1LL;
    for (int i = 1; i <= 500; ++i) {
        fat[i] = (int64(i) * fat[i-1]) % mod;
        ifat[i] = fpow(fat[i], mod-2);
    }
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, K, p;
        cin >> N >> K >> p;
        int64 res = (C(N-1, N-K) * fat[K-1]) % mod;
        for (int pos = K+1; pos < N; ++pos) {
            int need = pos - K;
            int64 psum = 0LL;
            for (int grt = p+1; grt <= N; ++grt) {
                psum += C(grt - 2, need-1);
            }
            res += ((psum%mod) * fat[N-need-1])%mod;
            res %= mod;
        }
        cout << "Case #" << tc << ": " << res << "\n";
    }

	return 0;
}

















