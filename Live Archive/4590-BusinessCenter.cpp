#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    while (cin >> n >> m) {
        int res = 2e9;
        for (int i = 0; i < m; ++i) {
            int up, down;
            cin >> up >> down;
            
            int lo = 0, hi = n;
            int cur = 2e9;
            while (lo <= hi) {
                int mid = (lo+hi)>>1;
                
                int pos = mid * up - (n - mid)*down;
                
                if (pos > 0) {
                    cur = min(cur,pos);
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
                
            }
            res = min(res, cur);
        }
        cout << res << "\n";
    }
    
    return 0;
}