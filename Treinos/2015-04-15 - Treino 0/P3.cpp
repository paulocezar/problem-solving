#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int seen[128];
vector<int> gr[128];

int dumbbell(int u) {
    queue<int> q;
    q.push(u); seen[u] = 1;
    
    vector<int> els;
     
    while (!q.empty()) {
        u = q.front(); q.pop();
        els.push_back(u);

        for (auto &v : gr[u]) {
            if (!seen[v]) {
                seen[v] = 1;
                q.push(v);
            }
        }
    }
    
    if (els.size() & 1) return 0;
    if (els.size() == 2) return 1;
    
    sort(els.begin(), els.end(), [](const int &x, const int &y){ return gr[x].size() > gr[y].size(); });
    
    if ((gr[els[0]].size() == gr[els[1]].size()) &&
        (gr[els[2]].size() == gr[*els.rbegin()].size()) &&
        (gr[els[1]].size() == (gr[els[2]].size()+1))) {
            
            q.push(els[0]); seen[els[0]] = 2;
            int vtx = 0;
            
            while (!q.empty()) {
                u = q.front(); q.pop();
                vtx++;

                for (auto &v : gr[u]) {
                    if (((u == els[0]) && (v == els[1])) ||
                        ((u == els[1]) && (v == els[0]))) continue;
                    if (seen[v] == 1) {
                        seen[v] = 2;
                        q.push(v);
                    }
                }
            }
            if ((vtx<<1) == els.size()) return 1;
        }
    
    return 0;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M; cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            gr[i].clear();
            seen[i] = 0;
        }
        
        while (M--) {
            int a, b; cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        
        int dumbbells = 0;
        for (int i = 1; i <= N; ++i) {
            if (!seen[i]) {
                dumbbells += dumbbell(i);
            }
        }
        cout << "Case #" << tc << ": " << dumbbells << "\n";
        
    }

	return 0;
}

















