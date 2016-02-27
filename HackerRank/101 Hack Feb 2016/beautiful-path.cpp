#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> gr[1<<10];
char seen[1<<10];

bool has_path(int from, int to, int mask) {
    memset(seen, 0, sizeof(seen));
    queue<int> q;
    q.push(from); seen[from] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == to) return true;

        for (auto &w : gr[u]) {
            if (seen[w.first]) continue;
            if ((mask | w.second) != mask) continue;
            q.push(w.first); seen[w.first] = 1;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    int u, v, c;    
    while (M--) {
        cin >> u >> v >> c;
        gr[u].push_back(make_pair(v, c));
        gr[v].push_back(make_pair(u, c));
    }

    int A, B;
    cin >> A >> B;

    int dist = 1023;
    int bit = 1<<9;
    if (!has_path(A, B, dist)) dist = -1;
    else while (bit) {
        dist ^= bit;
        if (!has_path(A, B, dist)) dist ^= bit;
        bit >>= 1;
    }

    cout << dist << endl;

	return 0;
}
