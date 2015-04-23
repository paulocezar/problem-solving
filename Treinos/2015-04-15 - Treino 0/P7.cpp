#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int assist[] = {0, 4, 8, 11};

int dp[2][4][16][64];

int stpnss[1024];
int N, tot;

/*int solve(int pos, int lvl, int K, int en) {
    if (pos == N) return 0;
    if (en == 0) return tot;
    
    int &ret = dp[pos][lvl][K][en];
    if (cached[pos][lvl][K][en] == cached_now) return ret;
    cached[pos][lvl][K][en] = cached_now;
    ret = 1e9;
        
    tot -= stpnss[pos];
    for (int nlvl = 0; nlvl < 4; ++nlvl) {
        if (nlvl == 0) ret = min(ret, stpnss[pos] + solve(pos+1, nlvl, K, 0));
        if ((nlvl != lvl) && !K) continue;
        if (nlvl > en) continue;
        ret = min(ret, max(0, stpnss[pos]-assist[nlvl]) + solve(pos+1, nlvl, K-((nlvl==lvl)?0:1), en-nlvl));
    }
    tot += stpnss[pos];
    
    return ret;    
}*/

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int K, E;
        cin >> N >> K >> E;
        
        for (int i = 0; i < N; ++i) {
            cin >> stpnss[i];
        }
        
        int old = 0, cur = 1;
        
        tot = 0;
        stpnss[N] = 0;
        
        for (int pos = N; pos >= 0; --pos) {
            old = 1-old, cur = 1-cur;
            tot += stpnss[pos];
            for (int lvl = 0; lvl < 4; ++lvl) {
                for (int k = 0; k <= K; ++k) {
                    for (int en = 0; en <= E; ++en) {
                        int &ret = dp[cur][lvl][k][en];
                        
                        if (pos == N) {
                            ret = 0;
                        } else if (en == 0) {
                            ret = tot;
                        } else {
                            ret = 1e9;
                            
                            for (int nlvl = 0; nlvl < 4; ++nlvl) {
                                if (nlvl == 0) ret = min(ret, stpnss[pos] + dp[old][nlvl][k][0]);
                                if ((nlvl != lvl) && !k) continue;
                                if (nlvl > en) continue;
                                ret = min(ret, max(0, stpnss[pos]-assist[nlvl]) + dp[old][nlvl][k-((nlvl==lvl)?0:1)][en-nlvl]);
                            }
                        }       
                    }
                }
            }
        }
        
        cout << "Case #" << tc << ": " << dp[cur][0][K][E] << "\n";
    }
    

	return 0;
}

















