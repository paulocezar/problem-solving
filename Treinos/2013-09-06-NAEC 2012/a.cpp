#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, box[11][3];

int cache[1<<10][11][3];

int solve(int mask, int last, int rot) {
    
    if (!mask) return 0;
    int &res = cache[mask][last][rot];
    
    if (res == -1) {
        int x = 0, y = 0;
        switch (rot) {
            case 0: x = box[last][0], y = box[last][1]; break;
            case 1: x = box[last][0], y = box[last][2]; break;
            case 2: x = box[last][1], y = box[last][2]; break;
        }
    
        res = 0;
        for (int p = 0; p < n; ++p) if (mask & (1<<p)) {
         
            if (box[p][0] <= x && box[p][1] <= y)
                res = max(res, 1+solve(mask ^ (1<<p), p, 0));
    
            if (box[p][0] <= x && box[p][2] <= y)
                res = max(res, 1+solve(mask ^ (1<<p), p, 1));
    
            if (box[p][1] <= x && box[p][2] <= y)
                res = max(res, 1+solve(mask ^ (1<<p), p, 2));
        
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int tc = 1;
    box[10][0] = box[10][1] = box[10][2] = 2e9;
    
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> box[i][j];
            }
            sort(box[i], box[i]+3);
        }
        memset(cache,-1,sizeof(cache));
        cout << "Case " << tc++ << ": " << solve((1<<n)-1, 10, 0) << "\n";
    }
    
    return 0;
}
