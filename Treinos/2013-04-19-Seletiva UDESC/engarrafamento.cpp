#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int N;
    while ((cin >> N) && N) {
        
        double s0 = 0.0;
        double v0 = 0.0;
        double last = 0;
        double a, b;
        
        for (int i = 0; i < N; ++i) {
            
            cin >> a >> b;
            
            double t = min(v0 / 2.0, a-last);
            s0 = s0  + v0 * t - t*t;
            v0 = v0 - 2.0*t;
            
            t = min(10.0 - v0, b-a);
            s0 = s0 + v0 * t + t * t / 2.0;
            v0 = v0 + t;
            
            double rem = (b-a) - t;
            s0 = s0 + v0*rem;
            
            last = b;
        }
        cout << s0 << "\n";
        
    }
    
    return 0;
}