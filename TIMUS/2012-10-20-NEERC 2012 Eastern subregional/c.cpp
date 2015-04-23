#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXH 256

int dx[8] = {-1, 0, 1, 0,-1,-1, 1, 1};
int dy[8] = { 0,-1, 0, 1,-1, 1,-1, 1};

int get(int xd, int yd) {
    switch (xd) {
        case -1:
        switch(yd) {
            case -1: return 4; 
            case 0: return 0;
            case 1: return 5;
        }
        break;
        case 0:
        switch(yd) {
            case -1: return 1;
            case 1: return 3;
        }
        break;
        case 1:
        switch(yd) {
            case -1: return 6;
            case 0: return 2;
            case 1: return 7;
        }
        break;
    }
    return -1;
}

int dist[ 256 ][ 256 ][ 8 ];
int H, W;

string layout[2*MAXH+1];

struct state_t {
    int x, y, d;
    explicit state_t(int a = 0, int b = 0, int c = 0) : x(a), y(b), d(c) {}
};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    cin >> H >> W; cin.ignore();
    
    REP(i,2*H+1) getline(cin,layout[i]);
    
    int xs, ys, ds;
    FOR (i,1,H) FOR(j,1,W) {
        int x = 2*i-1;
        int y = 2*j-1;
        
        if (layout[x][y] != ' ') {
            REP(dir,8) {
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                if (ni < 1 || ni > H || nj < 1 || nj > W) continue;
                int nx = 2*ni-1;
                int ny = 2*nj-1;
                if (layout[nx][ny] != ' ') {
                    xs = i, ys = j, ds = dir;
                    break;
                } 
            }
            break;
        }
    }
    
    memset(dist,0x3F,sizeof(dist));
    dist[ xs ][ ys ][ ds ] = 0;
    
    queue< state_t > q;
    q.push(state_t(xs,ys,ds));
	while (!q.empty()) {
	    
        xs = q.front().x;
        ys = q.front().y;
        ds = q.front().d; q.pop();
        
        int xb = xs+dx[ds];
        int yb = ys+dy[ds];
        
        bool outa = (xs < 1) || (xs > H) || (ys < 1) || (ys > W);
        bool outb = (xb < 1) || (xb > H) || (yb < 1) || (yb > W);
        //cout << xs << " " << ys << " .. " << xb << " " << yb << endl;
        if (outa && outb) {
            cout << dist[xs][ys][ds] << "\n";
            return 0;
        }
        
        REP(dir,4) {
            
            int xx = 2*xs - 1;
            int yy = 2*ys - 1;
            
            int nx = xx+dx[dir];
            int ny = yy+dy[dir];
            bool ok = ((nx < 0) || (nx >= 2*H+1) || (ny < 0) || (ny >= 2*W+1));
            if (!ok) ok = (layout[nx][ny] == '.');
            int nd = get(xb-xs-dx[dir],yb-ys-dy[dir]);
            if (ok) ok = (nd != -1);
            
            if (ok && (dist[xs][ys][ds]+1 < dist[xs+dx[dir]][ys+dy[dir]][nd])) {
                dist[xs+dx[dir]][ys+dy[dir]][nd] = dist[xs][ys][ds]+1;
                q.push(state_t(xs+dx[dir],ys+dy[dir],nd));
            }
        }
        
        REP(dir,4) {
            
            int xx = 2*xb - 1;
            int yy = 2*yb - 1;
            
            int nx = xx+dx[dir];
            int ny = yy+dy[dir];
            
            bool ok = ((nx < 0) || (nx >= 2*H+1) || (ny < 0) || (ny >= 2*W+1));
            if (!ok) ok = (layout[nx][ny] == '.');
            
            int nd = get(xb+dx[dir]-xs,yb+dy[dir]-ys);
            if (ok) ok = (nd != -1);
            
            if (ok && (dist[xs][ys][ds]+1 < dist[xs][ys][nd])) {
                dist[xs][ys][nd] = dist[xs][ys][ds]+1;
                q.push(state_t(xs,ys,nd));
            }
        }
            
            
	}
    cout << "Death\n";    
	return 0;
}

















