#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int R, C;
        cin >> R >> C;
        string grid[R];
        bool up[R][C], dw[R][C], lf[R][C], rt[R][C];
         
        for (int i = 0; i < R; ++i) {
            cin >> grid[i];
            for (int j = 0; j < C; ++j) {
                up[i][j] = dw[i][j] = lf[i][j] = rt[i][j] = true;
            }
        }
        
        
        for (int j = 0; j < C; ++j) {
            int i = 0;
            while (i < R) {
                if (grid[i][j] != '.') {
                    up[i][j] = false;
                    break;
                }
                i++;
            }
        }

        for (int j = 0; j < C; ++j) {
            int i = R-1;
            while (i >= 0) {
                if (grid[i][j] != '.') {
                    dw[i][j] = false;
                    break;
                }
                i--;
            }
        }
        
        for (int i = 0; i < R; ++i) {
            int j = 0;
            while (j < C) {
                if (grid[i][j] != '.') {
                    lf[i][j] = false;
                    break;
                }
                j++;
            }
        }

        for (int i = 0; i < R; ++i) {
            int j = C-1;
            while (j >= 0) {
                if (grid[i][j] != '.') {
                    rt[i][j] = false;
                    break;
                }
                j--;
            }
        }

        int ans = 0;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '.') continue;
                if (up[i][j] || dw[i][j] || lf[i][j] || rt[i][j]) {
                    switch (grid[i][j]) {
                        case '^': if (!up[i][j]) ans++; break;
                        case 'v': if (!dw[i][j]) ans++; break;
                        case '<': if (!lf[i][j]) ans++; break;
                        case '>': if (!rt[i][j]) ans++; break;
                    }
                } else {
                    ans = -1;
                    goto hell;
                }
            }
        }
    hell:    
        cout << "Case #" << tc << ": ";
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";

        
    }

	return 0;
}

















