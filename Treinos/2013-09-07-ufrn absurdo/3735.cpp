#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int64;

int64 tr[128][128], id[128][128], ax[128][128];

int main() {
    
    ios::sync_with_stdio(false);
        
    int n, m, k;
    while (cin >> n >> m >> k && (n || m || k)) {
        
        for (int i = 0; i <= n; ++i) 
            for (int j = 0; j <= n; ++j)
                tr[i][j] = id[i][j] = ((i==j) ? 1 : 0);
        
        while (k--) {
            char mv; int i, j;
            cin >> mv >> i;
            
            if (mv == 'g') {
                tr[i][0]++;
            } else if (mv == 'e') {
                for (int k = 0; k <= n; ++k) tr[i][k] = 0;
            } else {
                cin >> j;
                for (int k = 0; k <= n; ++k) swap(tr[i][k], tr[j][k]);
            }
        }
        
        while (m > 0) {
            
            if (m & 1) {
                
                for (int i = 0; i <= n; ++i) {
                    for (int k = 0; k <= n; ++k) if (id[i][k]) {
                        for (int j = 0; j <= n; ++j) {
                            ax[i][j] += id[i][k] * tr[k][j];
                        }
                    }
                }
                for (int i = 0; i <= n; ++i) 
                    for (int j = 0; j <= n; ++j) {
                        id[i][j] = ax[i][j];
                        ax[i][j] = 0;
                    }
            }
            
            
            for (int i = 0; i <= n; ++i) {
                for (int k = 0; k <= n; ++k) if (tr[i][k]) {
                    for (int j = 0; j <= n; ++j) {
                        ax[i][j] += tr[i][k] * tr[k][j];
                    }
                }
            }
            for (int i = 0; i <= n; ++i) 
                for (int j = 0; j <= n; ++j) {
                    tr[i][j] = ax[i][j];
                    ax[i][j] = 0;
                }
            
            m >>= 1;
        }
        
        cout << id[1][0];
        for (int i = 2; i <= n; ++i) {
            cout << " " << id[i][0];
        }
        cout << "\n";
    }
    
    return 0;
}