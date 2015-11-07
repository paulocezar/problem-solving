#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dist[2][1<<11][1<<11];

int best[4][1<<11];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, S, T;
    cin >> N;

    for (int way = 0; way < 2; ++way) {
    	for (int i = 1; i <= N; ++i) {
    		for (int j = 1; j <= N; ++j) {
    			cin >> dist[way][i][j];
    		}
    	}
    }
    	
    cin >> S >> T;

    for (int i = 0; i < 4; ++i) {
    	for (int j = 1; j <= N; ++j) {
    		best[i][j] = 2e9;
    	}
    }

    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0,make_pair(S, 0))); best[0][S] = 0;
    q.push(make_pair(0,make_pair(S, 1))); best[1][S] = 0;

    int ans = 2e9;

    while (!q.empty()) {
    	int now = -q.top().first;
    	int u = q.top().second.first;
    	int how = q.top().second.second; q.pop();

    	if (now > best[how][u]) continue;

    	if ((u == T) && (how > 1)) {
    		ans = now; break;
    	} 
    	
    	int way = how & 1;
    	for (int i = 1; i <= N; ++i) {
    		if (i == u) continue;
    		int cur = now+dist[way][u][i];
    		if (cur < best[how][i]) {
    			best[how][i] = cur;
    			q.push(make_pair(-cur,make_pair(i,how)));
    		}
    	}

    	if ((how < 2) && (u != S) && (u != T)) {
    		way = 1-way;
    		how = 3-how;
    		for (int i = 1; i <= N; ++i) {
    			if (i == u) continue;
    			int cur = now + dist[way][u][i];
    			if (cur < best[how][i]) {
    				best[how][i] = cur;
    				q.push(make_pair(-cur,make_pair(i,how)));
    			}
    		}
    	}

    }

    cout << ans << "\n";


	return 0;
}
