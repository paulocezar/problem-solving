#include <iostream>

using namespace std;

typedef long long int64;

int64 ax[2][2];

void mult(int64 a[][2], int64 b[][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ax[i][j] = 0LL;
            for (int k = 0; k < 2; ++k) {
                ax[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = ax[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    int64 plus, times;
    int n;
    
    while (cin >> plus >> times) {
        
        //cin >> plus >> times;
        if (!(cin >> n)) break;
        
        if (n == 0) { cout << "2\n"; continue; }
         
         n--;
        
        int64 tr[2][2] = {{plus, -times},
                          {1LL, 0LL}};  
                                
        int64 id[2][2] = {{1LL, 0LL},
                          {0LL, 1LL}};
        
        while (n > 0) {
            
            if (n & 1) mult(id, tr);
            mult(tr, tr);
            
            n >>= 1;
        }
            
        cout << (plus * id[0][0] + 2LL * id[0][1]) << "\n";
        
    }
    
    return 0;
}