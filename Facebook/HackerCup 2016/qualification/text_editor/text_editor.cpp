#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int len[303];
int lcp[303][303];
int cached[303][303][303];
int last_cached[303][303][303], cached_now;

int solve(int at, int need, int last) {
	if (!need) return 0;
	int &ret = cached[at][need][last];
	int &lc = last_cached[at][need][last];
	if (lc == cached_now) return ret;
	lc = cached_now;
	ret = 2e9;
	if (need <= at) ret = solve(at-1, need, last);
	ret = min(ret, len[at]-lcp[at][last]+solve(at-1, need-1, at));
	return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, K, N;

    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N >> K;
    	vector<string> word(N);
    	for (int i = 0; i < N; ++i) {
    		cin >> word[i];
    	}
    	sort(word.begin(), word.end());
    	word.push_back("");
    	for (int i = 0; i <= N; ++i) {
    		len[i] = word[i].size();
    		for (int j = i+1; j <= N; ++j) {
    			int &cur = lcp[i][j];
    			int mx = min(word[i].size(), word[j].size());
    			cur = 0;
    			while ((cur < mx) && (word[i][cur] == word[j][cur])) cur++;
    		}
    	}
    	cached_now++;
    	cout << "Case #" << tc << ": " << 2*solve(N-1, K, N)+K << "\n";
    }

    return 0;
}
