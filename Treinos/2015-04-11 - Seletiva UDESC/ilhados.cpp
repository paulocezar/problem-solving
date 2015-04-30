#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};

int N, M;
string g[1024];

void go(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (g[x][y] == '0') return;
    g[x][y] = '0';
    for (int dir = 0; dir < 4; ++dir) {
        go(x + dx[dir], y + dy[dir]);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    
    while (cin >> N >> M && N) {
        for (int i = 0; i < N; ++i) cin >> g[i];
        int flg = 0;
        for (int i = 0; i < N && flg < 2; ++i) {
            for (int j = 0; j < M && flg < 2; ++j) {
                if (g[i][j] == '1') { flg++; go(i, j); }
            }
        }
        if (flg == 2) cout << "isolados\n";
        else cout << "normal\n";
    }

	return 0;
}

















