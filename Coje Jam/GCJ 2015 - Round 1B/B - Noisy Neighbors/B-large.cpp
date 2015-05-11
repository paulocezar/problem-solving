#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};

int R, C, N;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> R >> C >> N;
        
        int grid[R][C];
        
        vector<int> opt1, opt2;
        
        int p = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (((i & 1) == (j & 1)) && (p < N)) {
                    grid[i][j] = 1;
                    p++;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j]) continue;
                int uh = 0;
                for (int dir = 0; dir < 4; ++dir) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (0 <= ni && ni < R && 0 <= nj && nj < C) {
                        uh += grid[ni][nj];
                    }
                }
                opt1.push_back(uh);
            }
        }
        
        int ans = 0;
        int rem = N - p;
        sort(opt1.begin(), opt1.end());
        for (int i = 0; i < rem; ++i) ans += opt1[i];
        
        p = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (((i & 1) != (j & 1)) && (p < N)) {
                    grid[i][j] = 1;
                    p++;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j]) continue;
                int uh = 0;
                for (int dir = 0; dir < 4; ++dir) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (0 <= ni && ni < R && 0 <= nj && nj < C) {
                        uh += grid[ni][nj];
                    }
                }
                opt2.push_back(uh);
            }
        }

        int ans2 = 0;
        rem = N - p;
        sort(opt2.begin(), opt2.end());
        for (int i = 0; i < rem; ++i) ans2 += opt2[i];
        
        
        cout << "Case #" << tc << ": " << min(ans,ans2) << "\n";
    }

	return 0;
}

















