#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 200200

vector< int > tree[MAXN]; 

int parent[MAXN], sons[MAXN];
int min_cost[MAXN], min_cost_color[MAXN], second_best[MAXN], ax[MAXN];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        
        for (int i = 1; i <= N; ++i) { tree[i].clear(); sons[i] = 0; }
        
        for (int i = 1; i <= N; ++i) {
            cin >> parent[i];
            tree[parent[i]].push_back(i);
        }
        
        queue<int> q;
        
        for (int i = 1; i <= N; ++i) {
            sons[i] = tree[i].size();
            if (!sons[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            
            if (tree[u].size()) {
                int MAXC = tree[u].size() + 1;
                
                int min_child_sum = 0;
                for (auto v : tree[u]) min_child_sum += min_cost[v];
                
                for (int color = 1; color <= MAXC; ++color) {
                    ax[color] = min_child_sum;
                }                

                for (auto v : tree[u]) {
                    if (min_cost_color[v] <= MAXC) {
                        ax[min_cost_color[v]] += second_best[v] - min_cost[v];
                    }
                }
                
                min_cost[u] = -1, second_best[u] = -1;
                for (int color = 1; color <= MAXC; ++color) {
                    ax[color] += color;
                    if ((min_cost[u] == -1) || (ax[color] < min_cost[u])) {
                        second_best[u] = min_cost[u];
                        min_cost[u] = ax[color];
                        min_cost_color[u] = color;
                    } else if ((second_best[u] == -1) || (ax[color] < second_best[u])) {
                        second_best[u] = ax[color];
                    }
                }                
                
            } else {
                min_cost[u] = 1;
                min_cost_color[u] = 1;
                second_best[u] = 2;
            }
            
            sons[parent[u]]--;
            if (parent[u] && !sons[parent[u]]) q.push(parent[u]);
        }
        
        cout << "Case #" << tc << ": " << min_cost[1] << "\n";
    }

	return 0;
}

















