#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 dp[1024];
int64 best_block[1024];
int64 block[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= M; ++i) dp[i] = 0LL;

    block[0] = 0LL;
	best_block[0] = 0LL;

    for (int i = 0; i < N; ++i) {

    	for (int j = 1; j <= M; ++j) best_block[j] = 0LL;

    	int leni;
    	cin >> leni;
    	for (int j = 1; j <= leni; ++j) {
    		cin >> block[j];
    		block[j] += block[j-1];
    	}

    	for (int j = 1; j <= leni; ++j) {
    		for (int len = 1; len <= min(j, M); ++len) {
    			best_block[len] = max(best_block[len], block[j]-block[j-len]);
    		}
    	}

    	for (int j = 1; j <= M; ++j) {
    		best_block[j] = max(best_block[j], best_block[j-1]);
    	}

    	for (int has = M; has > 0; --has) {
    		for (int put = 1; put <= has; ++put) {
    			dp[has] = max(dp[has], best_block[put] + dp[has-put]);
    		}
    	}
    }

    cout << dp[M] << "\n";


	return 0;
}
