#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100000
long long A[MAXN];
long long best[MAXN];

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for(int i = 0; i < N; ++i) cin >> A[i];
        
        long long sum = 0;
        long long mx = -2e9;
        for (int i = N-1; i >= 0; --i) {
            sum += A[i];
            mx = max(mx, sum);
            best[i] = mx;
            if (sum < 0LL) sum = 0;
        }
        
        
        sum = 0;
        mx = -2e9;
        long long res = -2e10;
        for (int i = 0; i+K+1 < N; ++i) {
            sum += A[i];
            mx = max(mx, sum);
            if (sum < 0LL) sum = 0LL;
            res = max(res, mx + best[i+K+1]);
        }
        cout << res << "\n";
    }
    
    return 0;
}
