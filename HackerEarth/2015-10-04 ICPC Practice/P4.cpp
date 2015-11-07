#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dist[1<<17];
int disappear[1<<17];

vector<pair<int,int>> gr[1<<17];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M, K, u, v;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
    	dist[i] = 2e9;
    }
    for (int i = 1; i <= M; ++i) {
    	disappear[i] = 2e9;
    	cin >> u >> v;
    	gr[u].push_back(make_pair(v,i));
    	gr[v].push_back(make_pair(u,i));
    }

    for (int i = 0; i < K; ++i) {
    	cin >> u >> v;
    	disappear[v] = u;
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
    	u = q.front(); q.pop();
    	int now = dist[u];
    	if (u == N) break;
    	for (auto &w : gr[u]) {
    		if (now >= disappear[w.second]) continue;
    		if (now+1 > dist[w.first]) continue;
    		dist[w.first] = now+1;
    		q.push(w.first);
    	}
    }

    if (dist[N] == 2e9) dist[N] = -1;
    cout << dist[N] << "\n";

    

	return 0;
}
