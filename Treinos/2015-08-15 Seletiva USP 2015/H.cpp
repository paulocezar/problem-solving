#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1024

int N, M;
vector< int > gr[MAXN];

bool seen[MAXN];		
int m[MAXN], m1[MAXN];
int idx[MAXN], r_idx[MAXN], color[MAXN];

int dfs(int u) {
	if (u < 0) return 1;
	if (seen[u]) return 0;
	seen[u] = true;
	for (auto vv : gr[r_idx[u]]) {
		int v = idx[vv];
        if (dfs(m1[v])) {
			m[u] = v;
			m1[v] = u;
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
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, NN, u, v;
    
    cin >> t;
    while (t--) {
        
        cin >> NN >> M;    
        for (int i = 0; i < NN; ++i) {
            idx[i] = -1;
            gr[i].clear();
        }
        
        while (M--) {
            cin >> u >> v; u--, v--;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        int qnt[2]; qnt[0] = qnt[1] = 0;
        
        queue<int> q;
        q.push(0);
        idx[0] = 0; qnt[0] = 1; r_idx[0] = 0;
        color[0] = 0;
        while (!q.empty()) {
            u = q.front(); q.pop();
            for (auto v : gr[u]) {
                if (idx[v] < 0) {
                    color[v] = 1-color[u];
                    idx[v] = qnt[color[v]]++;
                    if (color[v] == 0) r_idx[idx[v]] = v;
                    q.push(v);
                }
            }
        }
        
        N = qnt[0];
        M = qnt[1];
        
        cout << NN - bipMatch() << "\n";
    }
    
	return 0;
}


