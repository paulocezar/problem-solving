#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define EPS 1e-7

inline int sgn(long double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(long double a, long double b) { return sgn(a - b); }

long double romberg(long double a, long double b,
                    long double(*func)(long double)) {
    long double approx[2][25];
    long double *cur=approx[1], *prev=approx[0];

    prev[0] = 1/2.0 * (b-a) * (func(a) + func(b));
    for(int it = 1; it < 25; ++it, swap(cur, prev)) {
        if(it > 1 && cmp(prev[it-1], prev[it-2]) == 0)
            return prev[it-1];

        cur[0] = 1/2.0 * prev[0];
        long double div = (b-a)/pow(2.0, it);
        for(long double sample = a + div; sample < b; sample += 2 * div)
            cur[0] += div * func(a + sample);

        for(int j = 1; j <= it; ++j)
            cur[j] = cur[j-1] + 1/(pow(4.0, it) - 1)*(cur[j-1] + prev[j-1]);
    }

    return prev[24];
}


long double mid;
int K;

#define MAXK 15

long double P1[MAXK], Q1[MAXK], P2[MAXK], Q2[MAXK]; 

long double f(long double x) {
    long double num1 = 0.0, den1 = 0.0, num2 = 0.0 ,den2 = 0.0;
    
    for (int i = K; i >= 0; --i) {
        num1 = num1*x + P1[i];
        den1 = den1*x + Q1[i];
        num2 = num2*x + P2[i];
        den2 = den2*x + Q2[i];
    }
    
    long double res1 = num1 / den1;
    long double res2 = num2 / den2;
    
    if (mid > res1) return 0.0;
    
    if (mid > res2) return res1 - mid;
    return res1 - res2;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    int W, D, A;
    
    while (cin >>  W >> D >> A >> K) {
        for (int i = 0; i <= K; ++i) cin >> P1[i];
        for (int i = 0; i <= K; ++i) cin >> Q1[i];
        for (int i = 0; i <= K; ++i) cin >> P2[i];
        for (int i = 0; i <= K; ++i) cin >> Q2[i];
        
        long double lo = -D, hi = 0;
        for (int step = 0; step < 22; ++step) {
            mid = (lo + hi) * 0.5;
            if (cmp(romberg(0,W,f), A) < 0) hi = mid;
            else lo = mid;
        }
        cout << -lo << "\n";    
    }
    
    return 0;
}
