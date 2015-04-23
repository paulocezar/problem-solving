#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

double PS, PR, PI, PU, PW, PD, PL;

unordered_map<int, double> cache;

double solve(int start_point, int win, int lose, int inc, int dec) {
    if (!win) return 1.0;
    if (!lose) return 0.0;
    
    int idx = start_point;
        idx <<= 7; idx |= win;
        idx <<= 7; idx |= lose;
        idx <<= 7; idx |= inc;
        idx <<= 7; idx |= dec;
    
    if (cache.count(idx)) return cache[idx];    
    double res = 0.0;
    
    double psunny = (start_point ? ((start_point == 1) ? (1.0) : (PI)) : (0.0)) + (inc * PU) - (dec * PD);
    double prain = 1.0 - psunny;

    bool fixone = ((psunny + PU) - 1.0) > 1e-9;
    bool fixzero = (psunny - PD) < -1e-9;
    
    res += ((psunny * PS) + (prain * PR)) * (1.0-PW) * solve(start_point,win-1,lose,inc,dec);
    res += ((psunny * (1.0-PS)) + (prain * (1.0-PR))) * (1.0 - PL) * solve(start_point,win,lose-1,inc,dec);
    
    if (fixone) res += ((psunny * PS) + (prain * PR)) * PW * solve(1,win-1,lose,0,0);
    else        res += ((psunny * PS) + (prain * PR)) * PW * solve(start_point,win-1,lose,inc+1,dec);
    
    
    if (fixzero) res += ((psunny * (1.0-PS)) + (prain * (1.0-PR))) * PL * solve(0,win,lose-1,0,0);
    else         res += ((psunny * (1.0-PS)) + (prain * (1.0-PR))) * PL * solve(start_point,win,lose-1,inc,dec+1);
    
    cache[idx] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(6);
    
    int T, K;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> K >> PS >> PR >> PI >> PU >> PW >> PD >> PL;
        cache.clear();
        cout << "Case #" << kase << ": " << solve(2, K, K, 0, 0) << "\n";
    }
    
    return 0;
}
