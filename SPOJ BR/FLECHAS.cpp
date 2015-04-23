#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;

int dx[] = {-1, -1, -1,  0,  0, +1, +1, +1};
int dy[] = {-1,  0, +1, -1, +1, -1,  0, +1};
string name[] = {"NW", " N", "NE", " W", " E", "SW", " S", "SE"};
            //     0     1    2      3     4    5      6     7

int grid[16][16];
int N, total;
                // UP, LFT, RGT, DWN
int branch[][3] = {{5,6,7}, {2,4,7}, {0,3,5}, {0,1,2}};

pair<int, int> coord[4*8];

int apply(int x, int y, int dir) {
    x += dx[dir];
    y += dy[dir];
    int fix = 0;
    
    while (x >= 1 && y >= 1 && x <= N && y <= N) {
        
        if (grid[x][y]) grid[x][y]--, fix++;
        else {
            x -= dx[dir];
            y -= dy[dir];
            while (x >= 1 && y >= 1 && x <= N && y <= N) {
                grid[x][y]++;
                x -= dx[dir];
                y -= dy[dir];
            }            
            return 0;
        }
        
        x += dx[dir];
        y += dy[dir];
    }
    
    return fix;
}

void undo(int x, int y, int dir) {
    x += dx[dir];
    y += dy[dir];
    while (x >= 1 && y >= 1 && x <= N && y <= N) {
        grid[x][y]++;
        x += dx[dir];
        y += dy[dir];
    }
}

bool solve(int pos) {
    if (pos == 4*N) return total ? false : true;
    if ((4*N-pos)*N < total) return false;
    
    int x = coord[pos].first;
    int y = coord[pos].second;

    int b = 0;
    if (x == N+1) {
        b = 3;
    } else if (x) {
        b = y ? 2 : 1;
    }
    
    for (int bd = 0; bd < 3; ++bd) {
        int cover = apply(x, y, branch[b][bd]);
        
        if (cover) {
            total -= cover;
            if (solve(pos+1)) {
                undo(x, y, branch[b][bd]);
                grid[x][y] = branch[b][bd];
                return true;
            }
            total += cover;
            undo(x, y, branch[b][bd]);
        }
    }
    
    
    return false;
}

void printSolution() {
    cout << "  ";
    for (int i = 1; i <= N; ++i)
        cout << " " << name[grid[0][i]];
    cout << "   \n";
    
    for (int i = 1; i <= N; ++i) {
        cout << name[grid[i][0]];
        for (int j = 1; j <= N; ++j) {
            cout << " " << setw(2) << grid[i][j];
        }
        cout << " " << name[grid[i][N+1]] << "\n";
    }
    
    cout << "  ";
    for (int i = 1; i <= N; ++i)
        cout << " " << name[grid[N+1][i]];
    cout << "   \n";       
}

int main() {
    ios::sync_with_stdio(false);
    
    int inst = 1;
    while (cin >> N && N) {
        
        total = 0;
        
        int p = 0;
        
        for (int i = 1; i <= N; ++i) {
            coord[p++] = make_pair(i, 0);
            coord[p++] = make_pair(i, N+1);
            coord[p++] = make_pair(0, i);
            coord[p++] = make_pair(N+1, i);

            for (int j = 1; j <= N; ++j) {
                cin >> grid[i][j];
                total += grid[i][j];
            }
        }
        
        random_shuffle(coord, coord+p);
        for (int i = 0; i < 4; ++i) random_shuffle(branch[i], branch[i]+3);
        
        bool solvable = true;
        
        if (grid[1][1] > 6 || grid[1][N] > 6 || grid[N][1] > 6 || grid[N][N] > 6)
            solvable = false;
        
        if (solvable) solvable = solve(0);

        cout << "Instancia #" << inst++ << ":\n";
        if (solvable) printSolution();
        else cout << "sem solucao\n";
        cout << "\n";
    }
    
    
    return 0;
}