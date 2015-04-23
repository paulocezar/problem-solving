#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;

int dx[] = {0,+1,0,-1};
int dy[] = {+1,0,-1,0};

int board[7][7];
int put[7][7];
int light[7][7];
int mini[7][7], maxi[7][7], minj[7][7], maxj[7][7];

bool valid() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == -2 && !light[i][j]) return false;
            if (board[i][j] >= 0 && put[i][j] != board[i][j]) return false; 
        }
    }
    return true;
}

pair<int, int> cand[7*7];
int candsize;
int res;

void solve(int pos, int used) {
    
    if (used > res) return;
    
    if (pos == candsize) {
        if (valid()) res = min(res, used);
        return;
    }
    
    int i = cand[pos].first;
    int j = cand[pos].second;
        
    solve(pos+1, used);
    bool canput = !light[i][j];
    
    for (int dir = 0; dir < 4; ++dir) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
            put[ni][nj]++;
            if (board[ni][nj] >= 0 && put[ni][nj] > board[ni][nj]) canput = false;
        }
    }
    
    if (canput) {
        
        for (int ii = mini[i][j]; ii <= maxi[i][j]; ++ii) 
            light[ii][j]++;
        for (int jj = minj[i][j]; jj <= maxj[i][j]; ++jj)
            light[i][jj]++;
        
        solve(pos+1, used+1);
        
        for (int ii = mini[i][j]; ii <= maxi[i][j]; ++ii) 
            light[ii][j]--;
        for (int jj = minj[i][j]; jj <= maxj[i][j]; ++jj)
            light[i][jj]--;
    }
    
    for (int dir = 0; dir < 4; ++dir) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
            put[ni][nj]--;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    
    while (cin >> N >> M && (N || M)) {
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = -2;
        
        int B;
        cin >> B;
        while (B--) {
            int R, C, K;
            cin >> R >> C >> K;
            board[R-1][C-1] = K;
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                put[i][j] = 0;
                light[i][j] = 0;
                if (board[i][j] == -2) {
                    mini[i][j] = i;
                    while (mini[i][j]-1 >= 0 && board[mini[i][j]-1][j] == -2)
                        mini[i][j]--;
                    
                    maxi[i][j] = i;
                    while (maxi[i][j]+1 < N && board[maxi[i][j]+1][j] == -2)
                        maxi[i][j]++;   
                    
                    
                    minj[i][j] = j;
                    while (minj[i][j]-1 >= 0 && board[i][minj[i][j]-1] == -2)
                        minj[i][j]--;
                    
                    maxj[i][j] = j;
                    while (maxj[i][j]+1 < M && board[i][maxj[i][j]+1] == -2)
                        maxj[i][j]++;                          
                }
            }
        }
        
        candsize = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == -2) cand[candsize++] = make_pair(i, j);
        
        random_shuffle(cand, cand+candsize);
        
        res = 2e9;
        solve(0, 0);
        
        if (res == 2e9) cout << "No solution\n";
        else cout << res << "\n";
        
    }
    
    return 0;
}