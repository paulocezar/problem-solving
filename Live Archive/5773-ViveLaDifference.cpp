#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int a[2][4];
    while (true) {
        int sum = 0;
        for (int i = 0; i < 4; ++i) { cin >> a[0][i]; sum += a[0][i]; }
        if (sum == 0) break;
        
        int old = 0;
        int cur = 1;
        
        int step = 0;
        while ((a[old][0] != a[old][1]) || (a[old][1] != a[old][2]) || (a[old][2] != a[old][3])) {
            step++;
            
            a[cur][0] = abs(a[old][0]-a[old][1]);
            a[cur][1] = abs(a[old][1]-a[old][2]);
            a[cur][2] = abs(a[old][2]-a[old][3]);
            a[cur][3] = abs(a[old][3]-a[old][0]);
            
            old = !old;
            cur = !cur;            
        }
        cout << step << "\n";        
    }
    
    return 0;
}