#include <iostream>
#include <string>

using namespace std;

string grid[32];

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int N;
        cin >> N;
        
        int black = 0;
        
        string ans = "";
        
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
            for (int j = 0; j < N; ++j) if (grid[i][j] == '#')
                black++;
        }
        
        for (int i = 0; i < N && !ans.size(); ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '#') {
                    int nn = 0, mm = 0;
                    
                    while ((i+nn) < N && grid[i+nn][j] == '#') nn++;
                    while ((j+mm) < N && grid[i][j+mm] == '#') mm++;
                    
                    if (nn == mm && (nn*nn == black)) {
                        bool ok = true;    
                        for (int ii = i; ii < (i+nn); ++ii) {
                            for (int jj = j; jj < (j+nn); ++jj) {
                                if (grid[ii][jj] == '.') ok = false;
                            }
                        }
                        if (ok) { ans = "YES"; break; }
                    }
                    ans = "NO";
                    break;
                }
            }
        }
        cout << "Case #" << kase << ": " << ans << "\n";
        
    }
    
    return 0;
}
