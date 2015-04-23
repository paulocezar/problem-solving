#include <iostream>

using namespace std;

int n;

int grid[9][9], atblock[9][9];
int line[9], col[9], block[9];

bool solve(int i, int j) {
    if (i == n*n) return true;
    if (j == n*n) return solve(i+1, 0);
    
    if (grid[i][j]) return solve(i, j+1);

    for (int put = 1; put <= n*n; ++put) {
        if (line[i] & (1<<put)) continue;
        if (col[j] & (1<<put)) continue;
        if (block[atblock[i][j]] & (1<<put)) continue;
        
        grid[i][j] = put;
        line[i] |= (1<<put);
        col[j] |= (1<<put);
        block[atblock[i][j]] |= (1<<put);
        
        if (solve(i,j+1)) return true;
        
        grid[i][j] = 0;
        line[i] ^= (1<<put);
        col[j] ^= (1<<put);
        block[atblock[i][j]] ^= (1<<put);        
    }
    
    return false;
    
}


int main() {
    ios::sync_with_stdio(false);
    bool between = false;
    while (cin >> n) {
        if (between) cout << "\n";
        else between = true;
        
        for (int i = 0; i < n*n; ++i) {
            line[i] = col[i] = block[i] = 0;
            for (int j = 0; j < n*n; ++j) {
                cin >> grid[i][j];
                atblock[i][j] = n*(i/n) + (j/n);
            }
        }
    
        for (int i = 0; i < n*n; ++i) {
            for (int j = 0; j < n*n; ++j) {
                line[i] |= (1<<grid[i][j]);
                col[j] |= (1<<grid[i][j]); 
                block[atblock[i][j]] |= (1<<grid[i][j]);
            }   
        }
        
        if (solve(0,0)) {
            for (int i = 0; i < n*n; ++i) {
                for (int j = 0; j < n*n; ++j) {
                    if (j) cout << " ";
                    cout << grid[i][j];
                }
                cout << "\n";
            }
        } else cout << "NO SOLUTION\n";
    }
    
    return 0;
}