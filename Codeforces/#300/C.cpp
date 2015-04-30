#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int res = -1;
    
    int n, m;
    cin >> n >> m;
    
    int ld = -1, lh;
    int di, hdi;
    
    for (int i = 0; i < m; ++i) {
        cin >> di >> hdi;
        
        if (ld > 0) {
            int difd = di - ld;
            if (abs(hdi-lh) <= difd) {
                if (hdi >= lh) {
                    int up = hdi - lh;
                    int rem = difd - up;
                    up += rem / 2;
                    res = max(res, lh + up);
                } else {
                    int dw = lh - hdi;
                    int rem = difd - dw;
                    res = max(res, lh + (rem/2));
                }
            } else {
                ld = n, res = -1;
                break;
            }
            res = max(res, hdi);
        } else {
            res = max(res, hdi + di - 1);
        }
        
        ld = di, lh = hdi;
    }

    if (ld != n) {
        hdi += n-ld;
        res = max(res, hdi);
    }
    
    if (res >= 0) cout << res << "\n";
    else cout << "IMPOSSIBLE\n";

	return 0;
}

















