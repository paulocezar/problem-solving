#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1, 0,+1, 0};
int dy[] = { 0,-1, 0,+1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("lucky.in");
    ofstream out("lucky.out");

    int r, c;
    in >> r >> c;
    int grid[r][c];
    
    for (int i = 0; i < r; ++i) {
    	for (int j = 0; j < c; ++j) {
    		in >> grid[i][j];
    	}
    }

    int ans = 0;
    for (int i = 0; i < r; ++i) {
    	for (int j = 0; j < c; ++j) {
    		for (int dir = 0; dir < 4; ++dir) {
    			int win = true;
    			int ni = i+dx[dir], nj = j+dy[dir];
    			while (ni >= 0 && ni < r && nj >= 0 && nj < c) {
    				if (grid[ni][nj] >= grid[i][j]) {
    					win = false;
    					break;
    				}
    				ni += dx[dir];
    				nj += dy[dir];
    			}
    			if (win) ans++;
    		}
    	}
    }
    out << ans << "\n";

	return 0;
}
