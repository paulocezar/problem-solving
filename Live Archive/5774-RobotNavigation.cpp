#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define INF 0x3F3F3F3F
const int mod = 1000000;

int dist[101][101][4];
int ways[101][101][4];
//int calc[101][101][4], calc_now;

            // N E S W
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

inline int getdir(char c) {
    switch (c) {
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
    }
    return -1;
}

int minturns(int da, int db) {
    return min(abs(da-db), 4-abs(da-db));
}

string grid[101];



int main() {
    ios::sync_with_stdio(false);
    
    int N, M;
    while (cin >> N >> M && (N || M)) {
        
        for (int i = N-1; i >= 0; --i) cin >> grid[i];
        
        int xs, ys, ds, xt, yt;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < M; ++y) {
                for (int dir = 0; dir < 4; ++dir) {
                    dist[x][y][dir] = INF;
                    ways[x][y][dir] = 0;                    
                }
                
                if (getdir(grid[x][y]) != -1)
                    xs = x, ys = y, ds = getdir(grid[x][y]);
                
                if (grid[x][y] == 'X') 
                    xt = x, yt = y;
            }
        }
                
        dist[xs][ys][ds] = 0;
        ways[xs][ys][ds] = 1;
        priority_queue< pair< int, pair< pair<int,int>, int > > > q;
        q.push(make_pair(-dist[xs][ys][ds],make_pair(make_pair(xs,ys),ds)));
        
        while (!q.empty()) {
            int cst = -q.top().first;
            xs = q.top().second.first.first;
            ys = q.top().second.first.second;
            ds = q.top().second.second; q.pop();
         
            if (cst > dist[xs][ys][ds]) continue;

            for (int ndir = 0; ndir < 4; ++ndir) {
                if (ndir == ds) continue;
                if (minturns(ds,ndir) == 2) continue;
                int ncst = cst + minturns(ds,ndir);
                if (ncst < dist[xs][ys][ndir]) {
                    dist[xs][ys][ndir] = ncst;
                    ways[xs][ys][ndir] = ways[xs][ys][ds];
                    q.push(make_pair(-ncst,make_pair(make_pair(xs,ys),ndir)));
                } else if (ncst == dist[xs][ys][ndir]) {
                    ways[xs][ys][ndir] += ways[xs][ys][ds];
                    if (ways[xs][ys][ds] >= mod) ways[xs][ys][ds] -= mod;                    
                }
            }
            
            int nx = xs + dx[ds];
            int ny = ys + dy[ds];
            int ncst = cst + 1;
            while (0 <= nx && nx < N && 0 <= ny && ny < M && grid[nx][ny] != '*') {
                if (ncst < dist[nx][ny][ds]) {
                    dist[nx][ny][ds] = ncst;
                    ways[nx][ny][ds] = ways[xs][ys][ds];
                    q.push(make_pair(-ncst,make_pair(make_pair(nx,ny),ds)));
                } else if (ncst == dist[nx][ny][ds]) {
                    ways[nx][ny][ds] += ways[xs][ys][ds];
                    if (ways[nx][ny][ds] >= mod) ways[nx][ny][ds] -= mod;                    
                }                
                nx += dx[ds];
                ny += dy[ds];
            }
            
            
        }
        
        int best = INF;
        for (int dir = 0; dir < 4; ++dir) best = min(best,dist[xt][yt][dir]);
        
        if (best == INF) cout << "0 0\n";
        else {            
            int rways = 0;
            for (int dir = 0; dir < 4; ++dir) if(best == dist[xt][yt][dir]) {
                rways += ways[xt][yt][dir];
                if (rways >= mod) rways -= mod;
            }            
            cout << best << " " << rways << "\n";
        }
        
    }
    
    
    return 0;
}