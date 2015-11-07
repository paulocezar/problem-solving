#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int seen[3][128], seen_now;

int dx[] = {+1, 0,-1};
int dy[] = {+1,+1,+1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
    	seen_now++;
    	int n, k;
    	cin >> n >> k;
    	
    	string grid[3];
		for (int i = 0; i < 3; ++i) cin >> grid[i];

		int si = 0, sj = 0;
		
		if (grid[1][0] == 's') si = 1;
		else if (grid[2][0] == 's') si = 2;
		grid[si][sj] = '.';

		bool ok = false;

		queue<int> q;
		q.push((sj<<2) + si);
		seen[si][sj] = seen_now;
				
		while (!q.empty()) {
			sj = q.front(); q.pop();
			si = sj&3; sj >>= 2;

			bool out = true;
			for (int j = sj; out && (j < n); ++j) if (grid[si][j] != '.') {
				out = false;
			}

			if (out) {
				ok = true;
				break;
			}

			for (int dir = 0; dir < 3; ++dir) {
				int ni = si + dx[dir];
				int nj = sj + dy[dir];
				if ((0 <= ni) && (ni < 3) && (0 <= nj) && (nj < n)) {
					bool cool = true;
					for (int jj = nj; (jj < n) && (jj < (nj+3)); ++jj) {
						if (grid[ni][jj] != '.') {
							cool = false;
						}
					}
					if (grid[si][sj+1] != '.') cool = false;
					if (cool) {
						nj += 2;
						if (seen[ni][nj] != seen_now) {
							seen[ni][nj] = seen_now;
							q.push((nj<<2)|ni);
						}
					}
				}
			}
		}

		if (ok) cout << "YES\n";
		else cout << "NO\n";

    }

	return 0;
}
