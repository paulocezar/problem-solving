#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[2][64];
int b[64];

int dist[2][128][128];

int dx[2] = {0, +1};
int dy[2] = {+1, 0};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
	int n;
	cin >> n;

	for (int side = 0; side < 2; ++side) {
		for (int j = 1; j < n; ++j) {
			cin >> a[side][j];
		}
	}   

	for (int j = 1; j <= n; ++j) {
		cin >> b[j];
	}

	memset(dist, 0x3F, sizeof(dist));

	priority_queue<pair<int,int>> q;
	q.push(make_pair(0, ((2<<7)|2)<<1 ));
	dist[0][2][2] = 0;

	while (!q.empty()) {
		int d = -q.top().first;
		int s = q.top().second; q.pop();

		int differ = s&1; s >>= 1;

		int r1 = s&1; s >>= 1;
		int c1 = s&63; s >>= 6;
		int r0 = s&1; s >>= 1;
		int c0 = s;
		
		if (d > dist[differ][(c0<<1)|r0][(c1<<1)|r1]) continue;
		if (differ && (r0==r1) && (c0==c1) && (r0==1) && (c0==n)) break;

		for (int dir1 = 0; dir1 < 2; ++dir1) {
			int nr0 = r0 + dx[dir1];
			int nc0 = c0 + dy[dir1];
			if (nr0 < 2 && nc0 <= n) {
				for (int dir2 = 0; dir2 < 2; ++dir2) {
					int nr1 = r1 + dx[dir2];
					int nc1 = c1 + dy[dir2];
					if (nr1 < 2 && nc1 <= n) {
						int nd = d;
						if (dir1) nd += b[c0];
						else nd += a[r0][c0];

						if (dir2) nd += b[c1];
						else nd += a[r1][c1];

						int ndif = differ;
						if ((nr0!=nr1) || (nc0!=nc1)) ndif |= 1;
						int s0 = (nc0<<1) | nr0;
						int s1 = (nc1<<1) | nr1;
						if (nd < dist[ndif][s0][s1]) {
							dist[ndif][s0][s1] = nd;
							q.push(make_pair(-nd,(((s0<<7)|s1)<<1)|ndif));
						}

					}
				}

			}
		}

	}

	cout << dist[1][(n<<1)|1][(n<<1)|1] << "\n";

	return 0;
}
