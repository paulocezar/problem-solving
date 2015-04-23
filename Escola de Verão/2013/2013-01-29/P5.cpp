#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

int dx[] = {-1,-1,-1, 0,0, 1,1,1};
int dy[] = {-1, 0, 1,-1,1,-1,0,1};

int mines[32][32];
string grid[32];

int main(){
    ios::sync_with_stdio(false);
    int t;
	cin >> t;
	while (t--) {
		memset(mines,0,sizeof(mines));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> grid[i];
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 'F') {
					for (int dir = 0; dir < 8; ++dir) {
						int ni = i + dx[dir];
						int nj = j + dy[dir];
						if ((0 <= ni && ni < n) && (0 <= nj && nj < m)) {
							mines[ni][nj]++;
						}
					}
				}
			}
		}
		bool ok = true;
		bool onlymines = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] != 'F') {
					if (int(grid[i][j]-'0') != mines[i][j]) ok = false;
					onlymines = false;
				}
			}
		}

		

		if (ok && !onlymines) cout << "Well done Clark!\n";
		else cout << "Please sweep the mine again!\n";
	}
    return 0;
}
