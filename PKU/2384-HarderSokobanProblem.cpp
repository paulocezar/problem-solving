#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = {+1,0,-1,0};
int dy[] = {0,+1,0,-1};

int dist[25][25][25][25];
string grid[25];

struct pos_t {
    int i, j;
    pos_t(int ii = 0, int jj = 0) : i(ii), j(jj) {}
};

int main() {
    ios::sync_with_stdio(false);
    int N;
    while (cin >> N && N) {
        for (int i = 0; i < N; ++i) cin >> grid[i];
        
        int di, dj;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] == '*') di = i, dj = j;
        
        
        memset(dist,0x3F,sizeof dist);
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] == '.')
                    dist[i][j][di][dj] = 0;
        
        queue< pos_t > q;
        
        for (int dir = 0; dir < 4; ++dir) {
            int ni = di + dx[dir];
            int nj = dj + dy[dir];
            if (ni >= 0 && nj >= 0 && ni < N && nj < N) {
                if (grid[ni][nj] == '.') {
                    q.push(pos_t(ni,nj));
                    q.push(pos_t(di,dj));
                }
            }
        }
        
        int res = 0;
        while (!q.empty()) {
            pos_t player = q.front(); q.pop();
            pos_t container = q.front(); q.pop();
            
            int cur_dist = dist[player.i][player.j][container.i][container.j];
            res = max(res, cur_dist);
            
            for (int dir = 0; dir < 4; ++dir) {
                di = player.i + dx[dir];
                dj = player.j + dy[dir];
                if (di >= 0 && dj >= 0 && di < N && dj < N) {
                    if (di == container.i && dj == container.j) continue;
                    if (grid[di][dj] == '#') continue;
                    
                    if ((cur_dist+1) < dist[di][dj][container.i][container.j]) {
                        dist[di][dj][container.i][container.j] = cur_dist+1;
                        q.push(pos_t(di,dj));
                        q.push(container);
                    }
                    
                    int ni = container.i + dx[dir];
                    int nj = container.j + dy[dir];
                    if (ni == player.i && nj == player.j) {
                        if ((cur_dist+1) < dist[di][dj][ni][nj]) {
                            dist[di][dj][ni][nj] = cur_dist+1;
                            q.push(pos_t(di,dj));
                            q.push(pos_t(ni,nj));
                        }
                    }
                    
                }
            }
            
        }
        cout << res << "\n";
        
        
    }
    
    return 0;
}