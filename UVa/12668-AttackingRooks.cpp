#include <iostream>
#include <vector>

using namespace std;

string grid[128];
int hrz[128][128];
int vrt[128][128];

int N, M;
vector<int> gr[128*128];
bool seen[128*128];
int m1[128*128], m2[128*128];

int dfs(int u) {
    if (u < 0) return 1;
    if (seen[u]) return 0;
    seen[u] = true;
    for (size_t i = 0; i < gr[u].size(); ++i) {
        if (dfs(m2[ gr[u][i] ])) {
            m1[u] = gr[u][i];
            m2[ gr[u][i] ] = u;
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
    for (int i = 0; i < N; ++i) m1[i] = -1;
    for (int i = 0; i < M; ++i) m2[i] = -1;
    int aug, ans = 0;
    do {
        aug = 0;
        bool first = true;
        for (int i = 0; i < N; ++i) {
            if (m1[i] < 0 && gr[i].size()) {
                if (first) aug += dfsExp(i);
                else aug += dfs(i);
                first = false;
            }
        }
        ans += aug;
    } while (aug);
    return ans;
} 

int main() {
    ios::sync_with_stdio(false);

        int n;
        while (cin >> n) {
        
        for (int i = 0; i < n; ++i) cin >> grid[i];
        
        bool nw;
        
        N = 0;
        for (int i = 0; i < n; ++i) {
            nw = true;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X')
                    nw = true;
                else {
                    if (nw) N++;
                    hrz[i][j] = N;
                    nw = false;
                }
            }
        }
        
        M = 0;
        for (int j = 0; j < n; ++j) {
            nw = true;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 'X') nw = true;
                else {
                    if (nw) M++;
                    vrt[i][j] = M;
                    nw = false;
                }
            }
        }
        
        for (int i = 0; i < N; ++i) gr[i].clear();
                
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') continue;
                gr[ hrz[i][j]-1 ].push_back( vrt[i][j]-1 );
            }
        }

         cout << bipMatch() << "\n";
    }

    return 0;
}