#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 hp[2048], regen[2048];    

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, n, k;
    int64 h;
    
    cin >> t;
    
    while (t--) {
        cin >> n >> h >> k;
        for (int i = 0; i < n; ++i) cin >> hp[i] >> regen[i];
        
        while (n > k) {
            int idx = -1;
            int64 maxH = -1LL;
            
            for (int i = 0; i < n; ++i) {
                if (hp[i] >= h) continue;
                
                int64 nh = h - hp[i] + regen[i];
                if ((nh > maxH) || (nh == maxH && (hp[i] > hp[idx]))) {
                    maxH = nh;
                    idx = i;
                }
            }
            
            if (maxH > 0LL) {
                h = maxH;
                n--;
                hp[idx] = hp[n];
                regen[idx] = regen[n];
            } else break;
        }

        cout << (((h > 0LL) && (k >= n)) ? "Y\n" : "N\n");
    }
    
	return 0;
}


