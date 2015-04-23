#include <iostream>
#include <string>

using namespace std;

int best1[512][512];
int best2[512][512];
int dp1[512][512][2];
int dp2[512][512][2];
string grid[512];

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        
        int N, M;
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i) cin >> grid[i];
        
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dp1[i][j][0] = dp1[i][j][1] = 0;
                
                if (grid[i][j] == '.') {
                    if (j && (grid[i][j-1] == '.')) dp1[i][j][0] = best1[i][j-1] + 1;
                    if (i && (grid[i-1][j] == '.')) dp1[i][j][1] = best1[i-1][j] + 1;
                    if (!(i+j)) dp1[i][j][0] = dp1[i][j][1] = 1;
                }
                  
                best1[i][j] = max(dp1[i][j][0], dp1[i][j][1]);
                res = max(res, best1[i][j]);
            }
        }
        
        for (int i = N-1; i >= 0; --i) {
            for (int j = M-1; j >= 0; --j) {
                dp2[i][j][0] = dp2[i][j][1] = 0;
                if (grid[i][j] == '.') {
                    if ((j+1) < M) dp2[i][j][0] = best2[i][j+1];
                    if ((i+1) < N) dp2[i][j][1] = best2[i+1][j];
                    dp2[i][j][0]++;
                    dp2[i][j][1]++;
                }   
                best2[i][j] = max(dp2[i][j][0], dp2[i][j][1]);
            }
        }
        
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                
                if (dp1[i][j][0]) {
                    int up = 0;
                    while (((i-up) >= 0) && (grid[i-up][j] == '.')) {
                        res = max(res, dp1[i][j][0] + up + dp2[i-up][j][0] - 1);
                        up++;
                    }
                }
                
                if (dp1[i][j][1]) {
                    int left = 0;
                    while (((j-left) >= 0) && (grid[i][j-left] == '.')) {
                        res = max(res, dp1[i][j][1] + left + dp2[i][j-left][1] - 1);
                        left++;
                    }
                }       
            }
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
    return 0;
}
