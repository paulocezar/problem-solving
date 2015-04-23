#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int64;

const int64 mod = 10007;

int64 ax[4][4];
void mult(int64 a[4][4], int64 b[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ax[i][j] = 0LL;
            for (int k = 0; k < 4; ++k) {
                ax[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            ax[i][j] %= mod;
        }
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            a[i][j] = ax[i][j];
}

int main() {
    ios::sync_with_stdio(false);
        
    int tc;
    cin >> tc;
    while (tc--) {
        int64 tr[4][4] = {{2,1,1,0},
                        {1,2,0,1},
                        {1,0,2,1},
                        {0,1,1,2}};
        
        int64 id[4][4] = {{1,0,0,0},
                        {0,1,0,0},
                        {0,0,1,0},
                        {0,0,0,1}};
        
        int n;
        cin >> n;
        while (n > 0) {
            if (n & 1) mult(id, tr);
            mult(tr,tr);
            n >>= 1;
        }
        
        cout << id[0][0] << "\n";
        
    }
    
    return 0;
}