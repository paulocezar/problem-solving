#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	int L, N, M; int64 D;
    	cin >> L >> N >> M >> D;

    	priority_queue<pair<int64,int64>> washers;
    	for (int i = 0; i < N; ++i) {
    		int64 W;
    		cin >> W;
    		washers.push(make_pair(-W,W));
    	}

    	int64 ans = 0LL;
    	queue<int64> dryers;
    	while (L--) {
    		auto cur = washers.top(); washers.pop();
    		int64 washed_at = -cur.first;
    		cur.first -= cur.second;
    		washers.push(cur);

    		int64 dry_at = 0LL;
    		if (int(dryers.size()) == M) {
    			dry_at = dryers.front(); dryers.pop();
    		}
    		if (washed_at > dry_at) dry_at = washed_at;
    		dry_at += D;
    		dryers.push(dry_at);
    		ans = max(ans, dry_at);
    	}

    	cout << "Case #" << tc << ": " << ans << "\n";
    }

	return 0;
}
