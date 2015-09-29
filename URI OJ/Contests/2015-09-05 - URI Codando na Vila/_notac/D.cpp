#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double EPS = 1e-4;

inline int SGN(double a) {
    return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0)));
}

inline int CMP(double a, double b) {
    return SGN(a-b);
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);
    cout << fixed << setprecision(4);
    
    int N, A, x, mx;
    while (cin >> N >> A && (N || A)) {
        map<int, int> cnt;
        int64 tot = 0;
        mx = -1;
        for (int i = 0; i < N; ++i) {
            cin >> x;
            cnt[x]++;
            tot += x;
            mx = max(x, mx);
        }
        
        if (tot == A) {
            cout << ":D\n";
            continue;
        }
        
        double lo = 0.0, hi = mx+1.0, mid, cut = 0.0;
        for (int step = 0; step < 128; ++step) {
            mid = .5 * (lo+hi);
            cut = 0.0;
            for (auto &val : cnt) {
                if (CMP(val.first,mid) > 0) {
                    cut += double(val.second) * (val.first - mid);
                }
            }
            
            if (CMP(cut,A) < 0) hi = mid;
            else lo = mid;
        }
        
        if (!CMP(cut,A)) cout << lo << "\n";
        else cout << "-.-\n";
    }

    return 0;
}
