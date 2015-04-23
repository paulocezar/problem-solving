#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int A[128], B[128], C[128];
int dp[128][128][128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    while (cin >> N && N) {
        for (int i = N-1; i >= 0; --i) {
            cin >> A[i] >> B[i] >> C[i];
        }
        
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                for (int k = 0; k <= N; ++k) {
                    int &res = dp[i][j][k];
                    res = 0;
                    if (i && (A[i-1] & 1)) res = A[i-1] + dp[i-1][j][k];
                    if (j && (B[j-1] & 1)) res = max(res, B[j-1] + dp[i][j-1][k]);
                    if (k && (C[k-1] & 1)) res = max(res, C[k-1] + dp[i][j][k-1]);
                    if (i && j && ((A[i-1] + B[j-1]) < 15) && ((A[i-1] + B[j-1]) & 1)) {
                        res = max(res, (A[i-1] * B[j-1]) + dp[i-1][j-1][k]);
                    }
                    if (i && k && ((A[i-1] + C[k-1]) < 15) && ((A[i-1] + C[k-1]) & 1)) {
                        res = max(res, (A[i-1] * C[k-1]) + dp[i-1][j][k-1]);
                    }
                    if (j && k && ((B[j-1] + C[k-1]) < 15) && ((B[j-1] + C[k-1]) & 1)) {
                        res = max(res, (B[j-1] * C[k-1]) + dp[i][j-1][k-1]);
                    }
                    if (i && j && k && ((A[i-1] + B[j-1] + C[k-1]) < 15) && ((A[i-1] + B[j-1] + C[k-1]) & 1)) {
                        res = max(res, (A[i-1]*B[j-1]*C[k-1]) + dp[i-1][j-1][k-1]);  
                    }
                    
                }
            }
        }
        
        cout << dp[N][N][N] << "\n";
    }

	return 0;
}

















