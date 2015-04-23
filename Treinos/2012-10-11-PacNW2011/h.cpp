#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double a, b, c, d, m, t;

double f(double x){
    return a * pow(x, 3.0) + b * pow(x, 2.0) + c * pow(x, 1.0) + d;
}

int main(){
    while (cin >> a >> b >> c >> d >> m >> t) {
        double lo = 0.0, hi = 2e9, cnt = 100;
        
        while (cnt--) {
            double mid = (lo + hi)/2.0;
            
            if (t < f(mid)*m) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        printf("%.2lf\n", double(int(lo*100.0))/100.0);
    }
    
    return 0;
}

