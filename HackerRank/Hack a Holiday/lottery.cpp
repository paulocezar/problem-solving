#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N, M;

vector< int > gr[1<<14];
char seen[1<<14];        
int m[1<<14], m1[1<<17];

int dfs(int u) {
    if (u < 0) return 1;
    if (seen[u]) return 0;
    seen[u] = 1;
    for (auto v : gr[u]) {
        if (dfs(m1[v])) {
            m[u] = v;
            m1[v] = u;
            return 1;
        }
    }
    return 0;
}

int dfsExp(int u) {
    for (int i = 1; i <= N; ++i) seen[i] = 0;
    return dfs(u);
}


int bipMatch() {
    for (int i = 1; i <= N; ++i) m[i] = -1;
    for (int i = 1; i <= M; ++i) m1[i] = -1;
    int aug, ans = 0;
    do {
        aug = 0;
        bool first = true;
        for (int i = 1; i <= N; ++i) if (m[i] < 0) {
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
    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int qnt; cin >> qnt;
        while (qnt--) {
            int v; cin >> v;
            gr[i].push_back(v);
        }
    }
    cout << M-bipMatch() << endl;

	return 0;
}
