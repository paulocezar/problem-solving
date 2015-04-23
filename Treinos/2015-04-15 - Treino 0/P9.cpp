#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char stat[1024];
int swtch[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, K;
        cin >> N >> K;
        
        for (int i = 0; i < K; ++i) { cin >> swtch[i]; }
        sort(swtch, swtch+K);
        
        int nn = 0;
        while ((nn < K) && (swtch[nn]*swtch[nn] <= N)) { nn++; }
       
        int res = 0;
        for (int mask = (1<<nn)-1; mask >= 0; --mask) {
            
            for (int i = 1; i <= N; ++i) stat[i] = 0;
            int x = mask;
            for (int p = 0; p < nn; ++p) {
                if (x & 1) {
                    for (int i = swtch[p]; i <= N; i += swtch[p]) {
                        stat[i] ^= 1;
                    }
                }
                x >>= 1; 
            }
            
            int get = 0;
            for (int i = 1; i <= N; ++i) get += stat[i];
            
            for (int p = nn; p < K; ++p) {
                int chng = 0;
                for (int i = swtch[p]; i <= N; i += swtch[p]) {
                    if (stat[i]) chng--;
                    else chng++;
                }
                if (chng > 0) get += chng;
            }
            res = max(res, get);
            
        }
        cout << "Case #" << tc << ": " << res << "\n";
        
    }

	return 0;
}

















