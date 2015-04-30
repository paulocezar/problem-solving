#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string grid[64];

string res[128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    vector<pair<int,int>> pieces;
    
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (grid[x][y] == 'o') {
                pieces.push_back(make_pair(x, y));
            }
        }
    }
    
    string ax = "";
    for (int i = 0; i < (2*n-1); ++i) ax += ".";
    for (int i = 0; i < (2*n-1); ++i) res[i] = ax;
    
    bool found = false;
    
    for (int dx = 1-n; dx < n; ++dx) {
        for (int dy = 1-n; dy < n; ++dy) {
            //if ((dx == 0) && (dy == 0)) continue;
            
            bool ok = true;
            bool us = false;
            
            for (auto piece : pieces) {
                int nx = piece.first + dx;
                int ny = piece.second + dy;
                if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < n)) {
                    if (grid[nx][ny] == '.') { ok = false; break; }
                    us = true;
                }
            }
            
            if (us && ok) {
                res[n-1+dx][n-1+dy] = 'x';
                found = true;
                for (auto piece : pieces) {
                    int nx = piece.first + dx;
                    int ny = piece.second + dy;
                    if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < n)) {
                        grid[nx][ny] = '#';
                    }
                }
            }
            
        }
    }
    
    res[n-1][n-1] = 'o';
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'x') found = false;
        }
    }
    
    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < (2*n-1); ++i) cout << res[i] << "\n";
    }
    
    

	return 0;
}

















