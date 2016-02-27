#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int _popcount[1<<16], _bit[16];

int worst[16], best[16], m[16], m1[16];
bool seen[16];

char done[1<<16], done_now;

int N, cur_x, cur_y;

vector< int > gr[16];

int dfs(int u) {
	if (u < 0) return 1;
	if (seen[u]) return 0;
	seen[u] = true;
	for (auto &v : gr[u]) {
		if ((cur_y & _bit[v]) && dfs(m1[v])) {
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
	for (int i = 0; i < N; ++i) {
		m[i] = -1;
		m1[i] = -1;
	}
	int aug, ans = 0;
	do {
		aug = 0;
		bool first = true;
		for (int i = 0; i < N; ++i) {
			if ((cur_x & _bit[i]) && (m[i] < 0)) {
				if (first) aug += dfsExp(i);
				else aug += dfs(i);
				first = false;
			}
		}
		ans += aug;
	} while (aug);
	return ans;
}

int placement(int won, int total) {
	if (won == total) return 1;
	return (1<<(total-won-1)) + 1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    	
    int _mx = 1<<16;
    _popcount[0] = 0;
    for (int i = 1; i < _mx; ++i) {
    	_popcount[i] = _popcount[i>>1] + (i&1);
    }

    for (int i = 0; i < 16; ++i) {
    	_bit[i] = (1<<i);
    }

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N;
    	int K = 0;
    	while ((1<<K) < N) K++;
    	
    	for (int i = 0; i < N; ++i) {
    		gr[i].clear();
    		worst[i] = 0;
    		best[i] = 0;
    		int Wij;
    		for (int j = 0; j < N; ++j) {
    			cin >> Wij;
    			if (Wij) gr[i].push_back(j);
    		}

    		if (int(gr[i].size()) == (N-1)) {
    			worst[i] = K;
    		}
    	}

    	done_now++;

    	queue<int> q;
    	q.push((1<<N) - 1);
    	done[(1<<N)-1] = done_now;

    	int victories = 0;
    	while (!q.empty()) {
    		int cur_sz = q.size();
    		while (cur_sz--) {
    			int competitors = q.front(); q.pop();
    			
    			for (int i = 0; i < N; ++i) {
    				if (competitors & _bit[i]) {
    					best[i] = victories;
    				}
    			}

    			int nxt_sz = _popcount[competitors] / 2;
    			for (cur_x = competitors; cur_x > 0; cur_x = (cur_x-1) & competitors) {
    				if (_popcount[cur_x] == nxt_sz) {
    					cur_y = competitors ^ cur_x;
    					if (done[cur_x] != done_now) {
    						int mtch = bipMatch();
    						if (mtch == nxt_sz) {
    							q.push(cur_x);
    							done[cur_x] = done_now;
    						}
    					}
    				}
    			}
    		}

    		victories++;
    	}

    	cout << "Case #" << tc << ": \n";
    	for (int i = 0; i < N; ++i) {
    		cout << placement(best[i], K) << " " << placement(worst[i], K) << "\n";
    	}
    }

	return 0;
}
