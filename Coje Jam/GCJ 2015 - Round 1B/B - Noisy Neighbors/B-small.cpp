#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int grid[16][16];

int R, C, N;

int solve(int x, int y, int rem) {
    if (!rem) {
        int uh = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (((j+1) < C) && grid[i][j] && grid[i][j+1]) uh++;
                if (((i+1) < R) && grid[i][j] && grid[i+1][j]) uh++;
            }
        }
        return uh;
    }
    if (y == C) return solve(x+1, 0, rem);
    if (x == R) return 1e9;
    int ret = solve(x, y+1, rem);
    grid[x][y] = 1;
    ret = min(ret, solve(x, y+1, rem-1));
    grid[x][y] = 0;
    return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> R >> C >> N;
        memset(grid, 0, sizeof(grid));
        cout << "Case #" << tc << ": " << solve(0, 0, N) << "\n";
    }

	return 0;
}

















