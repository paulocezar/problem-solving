#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int a[128];
int cnt[512];
int memo[128][128];
int lis[128];

vector<int> trs[128];

int n, m;

int solve(int pos, int used) {
	if (used == m) return 0;
	
	if (used > n) {
		int repeat = cnt[a[pos]];
		int last = max(repeat, lis[pos]);
		return ((m-used-1) * repeat) + last;
	}

	int &res = memo[pos][used];

	if (!res) {
		for (auto &tr : trs[pos]) {
			if (tr > pos) {
				res = max(res, solve(tr, used));
			} else {
				res = max(res, solve(tr, used+1));
			}
		}
		res++;
	}

	return res;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }

    for (int i = n-1; i >= 0; --i) {

    	lis[i] = 0;
    	for (int j = i+1; j < n; ++j) if (a[j] >= a[i]) {
    		lis[i] = max(lis[i], lis[j]);
    	}
    	lis[i]++;

    	trs[i].clear();
    	for (int j = 0; j < n; ++j) {
    		if (a[j] >= a[i]) {
    			trs[i].push_back(j);
    		}
    	}
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
    	ans = max(ans, solve(i, 0));
    }

    cout << ans << "\n";

    return 0;
}
