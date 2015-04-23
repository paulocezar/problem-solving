#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 10001

int N;
vector< int > gr[MAXN], ngr[MAXN];

int low[MAXN], lbl[MAXN], parent[MAXN];
int dfsnum;
// vector< pair<int,int> > brid;

void dfs(int u) {
	
    lbl[u] = low[u] = dfsnum++;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
        int v = gr[u][i];
		if (lbl[v] == -1) {
			parent[v] = u;
			dfs(v);
			if (low[v] > lbl[u]) {
			    ngr[u].push_back(v);
                ngr[v].push_back(u);
                // brid.push_back(make_pair(min(u,v), max(u,v)));
			}
				
			low[u] = min(low[u], low[v]);
		} else if (v != parent[u]) low[u] = min(low[u], lbl[v]);
	}
    
}

int count(int u) {
    int cnt = 0;
    lbl[u] = -1;
    if (gr[u].size() == ngr[u].size()) {
        cnt = 1;
        for (int i = 0; i < int(ngr[u].size()); ++i) {
            if (lbl[ngr[u][i]] != -1) cnt += count(ngr[u][i]);
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        int N, M;
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i) {
            gr[i].clear();
            ngr[i].clear();
            lbl[i] = -1;
        }
        while (M--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        dfsnum = 0;
        //brid.clear();
        for (int i = 0; i < N; ++i) if (lbl[i] == -1) dfs(i);
        
        //cout << "----" << endl;
        //for (int i = 0; i < int(brid.size()); ++i) 
        //   cout << ":: " << brid[i].first << " " << brid[i].second << endl;
        
        int res = 0;
        for (int i = 0; i < N; ++i) if (lbl[i] != -1) {
            int els = count(i);
            res += ((els * (els-1)) >> 1);
        }
        cout << "Case #" << kase << ": " << res << "\n";
        
    }
    
    return 0;
}
