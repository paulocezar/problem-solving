#include <iostream>

using namespace std;

typedef long long int64;

int64 a[2], b[2], c[2], d[2], e[2], sum[2], M;

int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        
        cin >> a[0] >> b[0] >> c[0] >> d[0] >> e[0] >> M;
        sum[0] = a[0] + b[0] + c[0] + d[0] + e[0];
        
        int k = 0;
        int64 pw = 1LL;
        
        while (k < 32) {
            
            if (pw * sum[0] >= M) break;
            
            k++;
            pw <<= 1;
        }
        if (k == 32) k = -1;
        
        
        cout << "Case #" << kase << ": " << k << "\n";
    }
    
    return 0;
}