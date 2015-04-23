#include <iostream>
#include <vector>

using namespace std;

#define MAXN 2048

int N, M;

vector< int > gr[MAXN];
bool seen[MAXN];		
int m[MAXN], m1[MAXN];

int dfs(int u) {
	if (u < 0) return 1;
	if (seen[u]) return 0;
	seen[u] = true;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		if (dfs(m1[ gr[u][i] ])) {
			m[u] = gr[u][i];
			m1[ gr[u][i] ] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp(int u) {
	for (int i = 0; i < N; ++i) seen[i] = false;
	return dfs(u);
}


int bipMatch() {
	for (int i = 0; i < N; ++i) m[i] = -1;
	for (int i = 0; i < M; ++i) m1[i] = -1;
	int aug, ans = 0;
	do {
		aug = 0;
		bool first = true;
		for (int i = 0; i < N; ++i) if (m[i] < 0) {
			if (first) aug += dfsExp(i);
			else aug += dfs(i);
			first = false;
		}
		ans += aug;
	} while (aug);
	return ans;
}

string grid[55];
int id[55][55];

#define NDIRS 4
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    
    int R, C;
    while (cin >> R >> C) {
        for (int i = 0; i < R; ++i) cin >> grid[i];
        
        N = 0, M = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 'X') continue;
                id[i][j] = (((i+j)&1) ? (N++) : (M++));
            }
        }
        
        int win = 1;
        if (N == M) {
            
            for (int i = 0; i < N; ++i) gr[i].clear();
            
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (grid[i][j] == 'X') continue;
                    if ((i+j)&1) {
                        for (int dir = 0; dir < NDIRS; ++dir) {
                            int ni = i + dx[dir];
                            int nj = j + dy[dir];
                            if ((ni >= 0) && (nj >= 0) && (ni < R) && (nj < C) && (grid[ni][nj] == '.')) {
                                gr[ id[i][j] ].push_back(id[ni][nj]);
                            }
                        }
                    }
                }
            }
            if (bipMatch() == N) win = 2;
            
        }
        cout << win << "\n";
    }
    
    return 0;
}