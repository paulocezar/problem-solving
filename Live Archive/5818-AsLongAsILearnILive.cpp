#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 128
vector< int > gr[MAXN];

int value[MAXN];
bool seen[MAXN];

int gogreed(int n) {
    int u = 0;
    seen[u] = true;
    queue<int> q; q.push(u);
    int res = 0;
    
    while (!q.empty()) {
        u = q.front(); q.pop();
        res += value[u];
        
        int bs = -1;
        for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
            int v = gr[u][i];
            if (seen[v]) continue;
            if (bs == -1 || (value[v] > value[bs])) bs = v;
        }
        if (bs != -1) { q.push(bs); seen[bs] = true; }
    }
    cout << res << " " << u << "\n";
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            gr[i].clear();
            seen[i] = false;
            cin >> value[i];
        }
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
        }
        
        cout << "Case " << tc << ": "; gogreed(n);
    }
    
    return 0;
}