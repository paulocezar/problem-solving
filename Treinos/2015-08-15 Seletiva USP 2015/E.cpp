#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};

string grid[1024];
int onfire[1024][1024];
int reached[1024][1024];
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, n, m;
    
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int sx, sy, ex, ey;
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
            for (int j = 0; j < m; ++j) {
                onfire[i][j] = 2e9;
                reached[i][j] = 2e9;
                if (grid[i][j] == 'S') sx = i, sy = j;
                else if (grid[i][j] == 'E') ex = i, ey = j;
                else if (grid[i][j] == 'F') {
                    onfire[i][j] = 0;
                    q.push(i*1000 + j);
                }
            }
        }
        while (!q.empty()) {
            int y = q.front() % 1000;
            int x = q.front() / 1000; q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (   0 <= nx && nx < n
                    && 0 <= ny && ny < m
                    && grid[nx][ny] != '#'
                    && onfire[nx][ny] > onfire[x][y]+1) {
                        onfire[nx][ny] = onfire[x][y] + 1;
                        q.push(nx*1000 + ny);
                    }
            }
        }
        
        bool gotout = false;
        q.push(sx*1000 + sy);
        reached[sx][sy] = 0;
        while (!q.empty() && !gotout) {
            sy = q.front() % 1000;
            sx = q.front() / 1000; q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = sx + dx[dir];
                int ny = sy + dy[dir];
                if (   0 <= nx && nx < n
                    && 0 <= ny && ny < m
                    && grid[nx][ny] != '#'
                    && reached[nx][ny] > reached[sx][sy]+1    
                    && onfire[nx][ny] > reached[sx][sy]+1) {
                        if (nx == ex && ny == ey) { gotout = true; break; }
                        reached[nx][ny] = reached[sx][sy]+1;
                        q.push(nx*1000 + ny);
                    }
            }
        }
        cout << (gotout ? "Y\n" : "N\n");
    }
	return 0;
}


