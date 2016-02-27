#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	int N;
    	cin >> N;

    	queue<int> q;
    	for (int i = 0; i < N; ++i) {
    		int ax; cin >> ax;
    		q.push(ax);
    	}

    	int cnt = 0;
    	int ans = 0;
    	int last;
    	
    	while (!q.empty()) {
    		int df = cnt ? (q.front() - last) : 1;
    		if (0 < df && df <= 10) {
    			last = q.front();
    			q.pop();
    		} else {
    			last += 10;
    			ans++;
    		}
    		cnt++;
    		if (cnt == 4) cnt = 0;
    	}

    	if (cnt) ans += 4-cnt;
    	cout << "Case #" << tc << ": " << ans << "\n";
    }

	return 0;
}
