#include <iostream>

using namespace std;

const int MOD = 1000000007;

int fastpow(int base, int d, int n) {
    int ret = 1;
    for(long long pow = base; d > 0; d >>= 1, pow = (pow * pow) % n)
        if(d & 1)
            ret = (ret * pow) % n;
    return ret;
}

long long subproblem(int a, int b, int c, int d, int n) {
    b = min(d, b); c = max(a, c);

    long long ans = fastpow(d-a+1, n, MOD);
    if(c > a) ans -= fastpow(c-a, n, MOD);
    if(d > b) ans -= fastpow(d-b, n, MOD);
    if(c > b+1) ans += fastpow(c-b-1, n, MOD);

    return (ans % MOD + MOD) % MOD;
}

int main() {
    int mu[1000001];
    mu[1] = 1;
    for(int i = 2; i <= 1000000; i++)
        mu[i] = 0;

    for(int i = 1; i <= 1000000; i++)
        for(int j = 2*i; j <= 1000000; j+=i)
            mu[j] -= mu[i];

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        long long ans = 0;
        int N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        for(int i = 1; i <= 1000000; i++) {
            int tmp = subproblem((A+i-1)/i, B/i, (C+i-1)/i, D/i, N);
            ans += (mu[i]*tmp + MOD) % MOD;
            if(ans >= MOD) ans -= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
