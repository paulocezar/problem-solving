#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[2048];
int difs[1<<13];
int dacm[1<<13];

int64 gcd(int64 a, int64 b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    sort(a, a+n);
    
    map<int, int> _difs;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            _difs[a[j] - a[i]]++;
        }
    }

    int M = 0;
    for (auto it = _difs.begin(); it != _difs.end(); ++it) {
        difs[M] = it->first;
        dacm[M] = it->second;
        it->second = M;
        M++;
    }

    dacm[M] = 0;
    for (int i = M-2; i >= 0; --i) {
        dacm[i] += dacm[i+1];
    }

    int64 rnum = 0LL;
    int64 rden = int64(dacm[0]) * int64(dacm[0]) * int64(dacm[0]);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            int val = difs[i] + difs[j];
            auto grt = _difs.upper_bound(val);
            if (grt == _difs.end()) break;
            int64 w1 = dacm[i+1]-dacm[i], w2 = dacm[j+1]-dacm[j], w3 = dacm[grt->second];
            rnum += w1*w2*w3;
        }
    }

    int64 gg = gcd(rnum, rden);
    rnum /= gg; rden /= gg;
    long double res = ((long double)rnum) / ((long double)rden);
    cout << res << endl;
    return 0;
}
