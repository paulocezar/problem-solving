#include <iostream>

using namespace std;

int a[1001];

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    while (cin >> n && n) {

        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int mx = -1, y;
        for (int i = 1; i < n-1; ++i) {
            int vl = a[i-1] + a[i] + a[i+1];
            if (vl > mx) {
                mx = vl;
                y = i;
            }
        }
        
        cout << mx << " " << (y+1) << "\n";
    }
    
    return 0;
}