#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        
        int n, aa;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> aa;
        cout << ((int64(n) * int64(n-1LL)) / 2LL) << "\n";        
        
           
    }
    
    return 0;
}
