#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

inline int sgn(long double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(long double a, long double b) { return sgn(a - b); }


int main() {
    ios::sync_with_stdio(false);
    
    string chambers;
    while (cin >> chambers) {
        
        int n = int(chambers.size());
        chambers += chambers[0];
        
        int loaded = 0;
        int emptypair = 0;
        for (int i = 0; i < n; ++i) {
            if (chambers[i] == '1') loaded++;
            else if (chambers[i+1] == '0') emptypair++;
        }
        
        double rotate = double(n-loaded) / double(n);
        double shoot = double(emptypair) / double(n-loaded);
        
        switch (cmp(rotate,shoot)) {
            case -1: cout << "SHOOT\n"; break;
            case 0: cout << "EQUAL\n"; break;
            case 1: cout << "ROTATE\n"; break;
        }
       
        
    }
    
    return 0;
}