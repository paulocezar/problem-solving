#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 101101

int N, pa[MAXN], id[MAXN], status[MAXN], cycle_pos[MAXN], dist[MAXN], enter_at[MAXN];

int P[MAXN][18];

bool cycle;
int cycle_head;

void go(int u) {
    status[u] = 1;
    cycle_pos[u] = -1;
    if (status[pa[u]] == 1) {
        cycle = true;
        cycle_head = pa[u];
        id[u] = cycle_head;
        cycle_pos[u] = 0;
        dist[u] = 0;
        enter_at[u] = u;
    } else if (status[pa[u]] == 2) {
        dist[u] = dist[pa[u]]+1;
        enter_at[u] = enter_at[pa[u]];
    } else {
        go(pa[u]);
        if (cycle) {
            id[u] = cycle_head;
            cycle_pos[u] = cycle_pos[pa[u]]+1;
            dist[u] = 0;
            enter_at[u] = u;
            if (u == cycle_head) cycle = false;
        } else {
            enter_at[u] = enter_at[pa[u]];
            dist[u] = dist[pa[u]]+1;
        }
    }
    status[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> N && N) {
        
        for (int i = 1; i <= N; ++i) {
            status[i] = 0;
            id[i] = i;
            cin >> pa[i];
        }
        
        cycle = false;
        for (int i = 1; i <= N; ++i) if (!status[i]) go(i);
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; (1<<j) <= N; ++j) {
                P[i][j] = -1;
            }
        }
        
        for (int i = 1; i <= N; ++i) {
            P[i][0] = id[pa[i]];
        }
        
        for (int j = 1; (1<<j) <= N; ++j) {
            for (int i = 1; i <= N; ++i) {
                if (P[i][j - 1] != -1) P[i][j] = P[P[i][j-1]][j-1];
            }
        }
        
        
        int Q;
        cin >> Q;
        while (Q--) {
            int a, b;
            cin >> a >> b;
            if (id[enter_at[a]] != id[enter_at[b]]) cout << "-1\n";
            else {
                int res = 0;
                if (enter_at[a] != enter_at[b]) {
                    res = dist[a] + dist[b];
                    a = enter_at[a], b = enter_at[b];
                    res += min(abs(cycle_pos[a] - cycle_pos[b]), 
                                cycle_pos[id[a]]+1-abs(cycle_pos[a] - cycle_pos[b]));
                } else {
                    res = dist[a] + dist[b];
                    if (dist[a] < dist[b]) swap(a,b);
                    
                    int lg = 1;
                    for (lg = 1; (1<<lg) <= dist[a]; ++lg);
                    lg--;
                    
                    int lca = -1;
                    for (int i = lg; i >= 0; --i)
                        if (dist[a] - (1<<i) >= dist[b])
                            a = P[a][i];
                    
                    if (a == b) lca = a;
                    else {
                        for (int i = lg; i >= 0; --i) {
                            if (P[a][i] != -1 && P[a][i] != P[b][i])
                                a = P[a][i], b = P[b][i];
                        }
                        lca = pa[a];
                    }
                    
                    res -= 2*dist[lca];
                }
                cout << res << "\n";
            }
            
        }
        
    } 
    
    return 0;
}