#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int, int> show[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	cin >> show[i].second >> show[i].first;
    }

    sort(show, show+n);

    multiset<int> recording;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	auto nxt = recording.upper_bound(show[i].second);
    	if (nxt != recording.begin()) {
    		nxt--;
    		recording.erase(nxt);
    		recording.insert(show[i].first);
    		ans++;
    	} else if (int(recording.size()) < k) {
    		recording.insert(show[i].first);
    		ans++;
    	}
    }

    cout << ans << "\n";

	return 0;
}
