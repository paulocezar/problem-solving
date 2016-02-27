#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int sqr(int val) { return val*val; }

int x[1<<11], y[1<<11], dist[1<<11];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N;
    	for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

    	int64 ans = 0LL;
    	for (int i = 0; i < N; ++i) {
    		for (int j = 0; j < N; ++j) {
    			dist[j] = sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
    		}
    		sort(dist, dist+N);
    		int cnt = 1;
    		for (int i = 1; i < N; ++i) {
    			if (dist[i] == dist[i-1]) cnt++;
    			else {
    				ans += ((cnt - 1) * cnt) >> 1;
    				cnt = 1;
    			}
    		}
    		ans += ((cnt - 1) * cnt) >> 1;
    	}

    	cout << "Case #" << tc << ": " << ans << "\n";
    }

	return 0;
}
