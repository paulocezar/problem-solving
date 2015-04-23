#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1, 0,+1, 0};
int dy[] = { 0,+1, 0,-1};

int dist[4][128][128];
int last_seen[4][128][128], seen_now;

int N, M;

string maze[128];

inline int direction(char c) { 
    switch (c) { 
        case '^': return 0;
        case '>': return 1;
        case 'v': return 2;
        case '<': return 3;
        case '#': return 4;
    }
    return -1;
}

inline bool is_valid(int x, int y) {
    return (0 <= x) && (x < N) && (0 <= y) && (y < M);    
}

bool might_go_and_doesnt_get_fried(int md, int x, int y) {
    if (direction(maze[x][y]) >= 0) return false;
    
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (is_valid(nx,ny)) {
            int d = direction(maze[nx][ny]);
            if (d >= 0) {
                if (d != 4) {
                    d = (d + md) & 3;
                    if (!(dx[dir] + dx[d]) && !(dy[dir] + dy[d])) return false;
                }
                break;
            }
            nx += dx[dir];
            ny += dy[dir];
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        
        cin >> N >> M;
        int si, sj;
        for (int i = 0; i < N; ++i) {
            cin >> maze[i];
            for (int j = 0; j < M; ++j) if (maze[i][j] == 'S') si = i, sj = j;
        }
        
        seen_now++;
        last_seen[0][si][sj] = seen_now;
        dist[0][si][sj] = 0;
        
        int ans = -1;
        
        queue<int> q;
        q.push((si << 7) | sj);
        while (!q.empty()) {
            int md = q.front(); q.pop();
            sj = md & 127; md >>= 7;
            si = md & 127; md >>= 7;
            int cur = dist[md][si][sj] + 1;
            md++; if (md == 4) md = 0;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = si + dx[dir];
                int ny = sj + dy[dir];
                if (is_valid(nx,ny)
                    && (last_seen[md][nx][ny] != seen_now)
                    && might_go_and_doesnt_get_fried(md,nx,ny)) {
                        dist[md][nx][ny] = cur;
                        if (maze[nx][ny] == 'G') { ans = cur; goto hell; }
                        last_seen[md][nx][ny] = seen_now;
                        q.push((md << 14) | (nx << 7) | ny);                    
                }
            }
        }
    hell:
        cout << "Case #" << tc << ": ";
        if (ans == -1) cout << "impossible\n";
        else cout << ans << "\n";
    }
    

	return 0;
}

















