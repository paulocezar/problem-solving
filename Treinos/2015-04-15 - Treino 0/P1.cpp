#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;

int64 fpow(int64 a, int x) {
    int64 ret = 1LL;
    while (x) {
        if (x & 1) ret = (a * ret) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return ret;
}

int64 fat[65], ifat[65];

int64 C(int n, int k) {
    if (n < k) return 0LL;
    return (((fat[n] * ifat[n-k])%mod) * ifat[k]) % mod;
}


int cache[8][8][65][1<<8];
int last_cached[8][8][65][1<<8], cached_now;

int N, M, K, all;

int solve(int i, int j, int ob, int mask) {
    
    if (j == M) return solve(i+1, 0, ob, mask);
    
    /*cout << i << " " << j << " " << ob << " ";
    for (int x = 0; x < M; ++x) if (mask & (1<<x)) cout << "1"; else cout << "0";
    cout << endl;*/
    
    
    if (i == N) {
        //cout << " : return = " << ((mask & (1<<(M-1))) ? 1 : 0) << endl;
        return ((mask & (1<<(M-1))) ? 1 : 0);
        
    }
    if (mask == 0) return 0;
    int &ret = cache[i][j][ob][mask];
    if (last_cached[i][j][ob][mask] == cached_now) return ret;
    last_cached[i][j][ob][mask] = cached_now;
    
    ret = 0;
    if ((ob+1) <= K) ret = solve(i, j+1, ob+1, mask & (all ^ (1<<j)));
    
    int reach = (mask & (1<<j)) | (j ? (mask & (1<<(j-1))) : (0));
    if (!reach) {
        ret += solve(i, j+1, ob, mask & (all ^ (1<<j)));
    } else {
        ret += solve(i, j+1, ob, mask | (1<<j));
    }     
    ret %= mod;
    return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    fat[0] = ifat[0] = 1LL;
    for (int i = 1; i <= 64; ++i) {
        fat[i] = (int64(i) * fat[i-1]) % mod;
        ifat[i] = fpow(fat[i], mod-2);
    }
    
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M >> K;
        cached_now++; all = (1<<M) - 1;
        int x = 0;
        for (int i = 0; i <= K; ++i) x = (x + C(N*M, i)) % mod;
        cout << "Case #" << tc << ": " << ((x - solve(0, 1, 0, 1) + mod) % mod) << "\n";
    }
    
    

	return 0;
}

















