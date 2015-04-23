#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int memo[16][1<<16];
int last_seen[16][1<<15], seen_now;
int visited[128][128], visited_now;

int dist[16][16];
int xpos[16], ypos[16];

int id[128][128];
string grid[128];

int dx[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
int dy[8] = {-1,+1,-2,+2,-2,+2,-1,+1};

int K;

int solve(int cur, int mask) {
    if (!mask) return dist[cur][0];
    
    int &ret = memo[cur][mask];
    if (last_seen[cur][mask] == seen_now) return ret;
    last_seen[cur][mask] = seen_now;
    ret = 2e9;
    
    for (int i = 0; i < K; ++i) if (mask & (1<<i)) {
        ret = min(ret, dist[cur][i+1] + solve(i+1, mask ^ (1<<i)));
    }
    
    return ret;    
}

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    while (cin >> N >> M >> K && N) {
        
        for (int i = 0; i < N; ++i) cin >> grid[i];
        
        int KK = 1;
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'P') {
                xpos[KK] = i, ypos[KK] = j;
                id[i][j] = KK++;
            } else if (grid[i][j] == 'C') {
                xpos[0] = i, ypos[0] = j;
                id[i][j] = 0;
            } else id[i][j] = -1;
        }
        
        for (int i = 0; i <= K; ++i) {
            visited_now++;
            queue< pair<int, int> > q;
            q.push(make_pair(xpos[i],ypos[i]));
            int cur_dist = 0;
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    int xx = q.front().first;
                    int yy = q.front().second; q.pop();
                    
                    if (id[xx][yy] != -1) dist[i][id[xx][yy]] = cur_dist;
                    
                    for (int dir = 0; dir < 8; ++dir) {
                        int nx = xx+dx[dir];
                        int ny = yy+dy[dir];
                        
                        if ((nx >= 0) && (ny >= 0) && (nx < N) && (ny < M) && (grid[nx][ny] != '#') && (visited[nx][ny] != visited_now)) {
                            q.push(make_pair(nx,ny));
                            visited[nx][ny] = visited_now;
                        }   
                    }
                    
                }
                cur_dist++;
            }
        }
        
        seen_now++;
        cout << solve(0,(1<<K)-1) << "\n";
        
    }

    return 0;
}

