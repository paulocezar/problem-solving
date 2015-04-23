#include <iostream>
#include <algorithm>

using namespace std;

int x[2014], y[1024];

int main() {
    ios::sync_with_stdio(false);
    
    int n, tc = 1;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        sort(x,x+n);
        sort(y,y+n);
        
        int dist = 0;
        int xc, yc;
        if (n&1) xc = x[n/2], yc = y[n/2];
        else xc = x[n/2-1], yc = y[n/2-1];
        
        for (int i = 0; i < n; ++i) {
            dist += abs(xc-x[i]);
            dist += abs(yc-y[i]);
        }
        
        cout << "Case " << tc++ << ": (" << xc << "," << yc << ") " << dist << "\n"; 
        
    }
    
    return 0;
}