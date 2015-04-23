#include <iostream>

using namespace std;

int acm[10][320][320];

int main() {
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int el;
            cin >> el;
            for (int k = 0; k < 10; ++k) {
                acm[k][i][j] = acm[k][i-1][j] + acm[k][i][j-1] - acm[k][i-1][j-1];
            }
            acm[el-1][i][j]++;
        }
    }
    
    int Q, x1, y1, x2, y2;
    cin >> Q;
    while (Q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for (int k = 0; k < 10; ++k) {
            int has = acm[k][x2][y2]-acm[k][x2][y1-1]-acm[k][x1-1][y2]+acm[k][x1-1][y1-1];
            if (has) {
                res++;
            }
        }
        cout << res << "\n";
    }
    
    
    return 0;
}