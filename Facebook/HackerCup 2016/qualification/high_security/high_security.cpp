#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
string grid[2];

int cached[1<<10][1<<4];
int last_cached[1<<10][1<<4], cached_now;

int solve(int at, int status) {
	
	int l0 = status >> 2;
	int l1 = status & 3;

	if (at == N) {
		if ((l0 == 1) || (l1 == 1)) return 2e9;
		return 0;
	}

	int &ret = cached[at][status];
	int &lc = last_cached[at][status];
	if (lc == cached_now) return ret;
	lc = cached_now;
	ret = 2e9;

	for (int i = 0; i < 2; ++i) {
		if ((grid[0][at] == 'X') && (l0 == 1)) continue;
		if ((grid[0][at] == 'X') && i) continue;		
		for (int j = 0; j < 2; ++j) {
			if ((grid[1][at] == 'X') && (l1 == 1)) continue;
			if ((grid[1][at] == 'X') && j) continue;

			int nl0 = l0;
			int nl1 = l1;
			
			if (grid[0][at] == 'X') nl0 = 0;
			else if (i) nl0 = 2;
			else if ((grid[0][at] == '.') && !j) nl0 = max(nl0, 1);

			if (grid[1][at] == 'X') nl1 = 0;
			else if (j) nl1 = 2;
			else if ((grid[1][at] == '.') && !i) nl1 = max(nl1, 1);

			ret = min(ret, i+j+solve(at+1,(nl0<<2) | nl1));
		}
	}

	return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N;
    	cin >> grid[0] >> grid[1];
    	cached_now++;
    	cout << "Case #" << tc << ": " << solve(0, 0) << "\n";
    }

	return 0;
}
