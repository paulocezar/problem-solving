#include <iostream>

typedef long long int64;

using namespace std;

const int64 mod = int64(1e9+7);

int64 mpot(int64 b, int e) {
    int64 res = 1;
    while (e > 0) {
        if (e & 1) {
            res *= b; res %= mod;
        }
        b *= b; b %= mod;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int64 res = 0;
    for (int i = 2; i < n; ++i) {
        n-1
    }
    res += mpw(n,n-1);
    if (res >= mod) res -= mod;    
    cout << res << "\n";
        
    return 0;
}
