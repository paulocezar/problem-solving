#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int64;
const int64 mod = 1000000000LL;


int height(int n) {
    if (n == 0) return -1;
    if (n == 1) return 0;
    int lg = 0; 
    while ((1<<(lg+1)) <= n) ++lg;
    return lg;
}

int64 dp[1430];
bool calc[1430];

int64 solve(int n) {
    
    if (n == 0 || n == 1) return 1LL;
    
    int64 &res = dp[n];
    if (calc[n]) return res;
    calc[n] = true;
    
    res = 0;
    
    int nn = n-1;
    for (int lf = 0; lf <= nn; ++lf) {
        int ds = abs(height(lf) - height(nn-lf));
        if (ds <= 1) res = (((solve(lf) * solve(nn-lf))%mod) + res)%mod;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) cout << setw(9) << setfill('0') << solve(n) << "\n";
        
    return 0;
}