#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int lo = 1, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo+hi) >> 1;

        int m23 = mid / 6;
        int m2 = mid / 2; m2 -= m23;
        int m3 = mid / 3; m3 -= m23;

        int nn = max(0, n-m2);
        int mm = max(0, m-m3);
        
        if ((nn+mm) <= m23) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << lo << "\n";


    return 0;
}
