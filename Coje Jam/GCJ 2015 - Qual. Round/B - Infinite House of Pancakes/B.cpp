#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int plate[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int D;
        cin >> D;
        for (int i = 0; i < D; ++i) cin >> plate[i];
        sort(plate, plate+D);
        int lo = 1, hi = plate[D-1];
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            
            bool ok = false;
            for (int special = 0; !ok && (special < mid); ++special) {
                int leqthn = mid - special;
                int id = D-1;
                int req = 0;
                while (id >= 0) {
                    if (plate[id] <= leqthn) break;
                    req += ((plate[id] + leqthn - 1) / leqthn) - 1;
                    if (req > special) break;
                    id--;
                }
                if (req <= special) ok = true;
            }
            
            if (ok) {
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
            
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }

	return 0;
}

















