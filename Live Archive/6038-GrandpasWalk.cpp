#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 55*55

vector<int> gr[MAXN];
int deg[MAXN];
int cnt[MAXN];

int grid[55][55];
int dx[] = {+1,0,+1,0};
int dy[] = {0,+1,0,+1};


int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> grid[i][j];

        for (int i = 0; i < N*M; ++i) {
            deg[i] = 0, gr[i].clear();
            cnt[i] = 0;
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int dir = 0; dir < 2; ++dir) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
                        if (grid[i][j] > grid[ni][nj]) {
                            gr[i*M + j].push_back(ni*M+nj);
                            deg[ni*M+nj]++;
                        } else if (grid[i][j] < grid[ni][nj]) {
                            gr[ni*M + nj].push_back(i*M+j);
                            deg[i*M+j]++;
                        }
                    }
                }
            }
        }
        
        queue<int> q;
        for (int i = 0; i < N*M; ++i) if (!deg[i]) {
            cnt[i] = 1;
            q.push(i);
        }
        
        int mxcnt = 0;
        
        while (!q.empty()) {
            
            int u = q.front(); q.pop();
            
            if (!gr[u].size()) mxcnt += cnt[u];
            
            for (int j = 0; j < int(gr[u].size()); ++j) {
                int v = gr[u][j];
                
                cnt[v] += cnt[u];
                deg[v]--;
                
                if (!deg[v]) q.push(v);
            }
            
        }
        
        cout << "Case #" << kase << ": " << mxcnt << "\n";
        
        
        
    }
    return 0;
}