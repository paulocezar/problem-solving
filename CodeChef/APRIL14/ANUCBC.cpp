#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int card[100001], qtd[128];
int64 dp[2][128], invmod[100002], ways[128];
    
const int64 mod = 1000000009LL;

int64 fpow(int64 a, int b) {
    int64 res = 1LL;
    while (b) {
        if (b & 1) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    for (int i = 1; i <= 100001; ++i) invmod[i] = fpow(i, mod-2LL);
    
    int T, N, Q, M, old, cur;
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 0; i < N; ++i) cin >> card[i];        
        
        while (Q--) {
            cin >> M;
            old = 0, cur = 1;
            
            for (int i = 0; i < M; ++i) qtd[i] = dp[0][i] = 0;
            
            for (int i = 0; i < N; ++i) qtd[((card[i]%M)+M)%M]++;
            
            dp[0][0] = 1LL;
            
            for (int curmod = 0; curmod < M; ++curmod) {
                if (!qtd[curmod]) continue;
                
                for (int j = 0; j < M; ++j) dp[cur][j] = 0;
                    
                for (int desir = 0; desir < M; ++desir) ways[desir] = 0LL;
                
                int qt = 0;
                int64 QTDcQT = 1LL;
                while (qt <= qtd[curmod]) {
                    ways[(qt * curmod) % M] += QTDcQT;
                    if (ways[(qt * curmod) % M] >= mod) ways[(qt * curmod) % M] -= mod;
                    
                    qt++;
                    QTDcQT = (((QTDcQT * int64(qtd[curmod] + 1LL - qt))%mod) * invmod[qt])%mod;
                }
                    
                for (int j = 0; j < M; ++j) {
                    for (int i = 0; i < M; ++i) {
                        dp[cur][(j + i)%M] += (ways[i] * dp[old][j])%mod;
                        if (dp[cur][(j + i)%M] >= mod) dp[cur][(j + i)%M] -= mod;
                    }   
                }
                cur = 1-cur;
                old = 1-old;
            }
            
            cout << dp[old][0] << "\n";
        }    
    }

	return 0;
}

















