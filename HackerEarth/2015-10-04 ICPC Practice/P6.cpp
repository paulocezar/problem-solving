#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

int has[2048];

int C[2048][2048];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, K, T;
    cin >> N >> K >> T;

    int min_sum = 0;
    for (int i = 0; i < K; ++i) {
    	int idx; cin >> idx;
    	has[idx] = 1;
    	min_sum += idx-1;
    }

    int missing = T - min_sum;

    if ((missing < 0) || (missing & 1) || (missing > 2*K)) {
    	cout << "0\n";
    } else {

    	C[0][0] = 1ULL;
    	for (int i = 1; i <= K; ++i) {
        	C[i][0] = C[i][i] = 1ULL;
        	for (int j = 1; j < i; ++j) {
        		C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        	}
    	}

    	missing >>= 1;
    	cout << C[K][missing] << "\n";
    }



	return 0;
}
