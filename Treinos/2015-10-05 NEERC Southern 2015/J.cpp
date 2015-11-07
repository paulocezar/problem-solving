#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
			 // U  R D L
int dx[] = {-1, 0,+1, 0};
int dy[] = { 0,+1, 0,-1};

int visited[4][16][16];
int counted[16][16];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int w, h;
    cin >> w >> h;

    string grid[w];
    for (int i = 0; i < w; ++i) {
    	cin >> grid[i];
    }

    int si = 0, sj = 0, sd = 0;
    for (int i = 0; i < w; ++i) {
    	for (int j = 0; j < h; ++j) {
    		if ((grid[i][j] != '.') && (grid[i][j] != '*')) {
    			si = i;
    			sj = j;
    			switch (grid[i][j]) {
    				case 'U': sd = 0; break;
    				case 'R': sd = 1; break;
    				case 'D': sd = 2; break;
    				case 'L': sd = 3; break;
    			}
    			break;
    		}
    	}
    }

    int res = 0;
    while (!visited[sd][si][sj]) {
    	if (!counted[si][sj]) {
    		counted[si][sj] = 1;
    		res++;
    	}
    	visited[sd][si][sj]++;
    	int ni = si+dx[sd];
    	int nj = sj+dy[sd];
    	if (0 <= ni && ni < w && 0 <= nj && nj < h && grid[ni][nj] != '*') {
    		si = ni;
    		sj = nj;
    	} else {
    		sd++;
    		if (sd == 4) sd = 0;
    	}
    }
    cout << res << "\n";



	return 0;
}
